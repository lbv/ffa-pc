#include <cstdio>
#include <vector>
using namespace std;


#define GetFS(b) ((b) & -(b))
#define ClrFS(b) (b &= ~GetFS(b))

#define For(t,i,c) for(t::iterator i=(c).begin(); i != (c).end(); ++i)

#define B(x) (1 << (x))
// create bitmask for 4 cells
#define MAKE_ROW4(a,b,c,d) (B(a)|B(b)|B(c)|B(d))
#define MAKE_ROW3(a,b,c)   (B(a)|B(b)|B(c))
#define MAKE_ROW2(a,b)     (B(a)|B(b))

typedef unsigned int u32;


char grid[4][5];

const u32 row_masks[] = {
	MAKE_ROW4( 0,  1,  2,  3),
	MAKE_ROW4( 4,  5,  6,  7),
	MAKE_ROW4( 8,  9, 10, 11),
	MAKE_ROW4(12, 13, 14, 15),

	MAKE_ROW4( 0,  4,  8, 12),
	MAKE_ROW4( 1,  5,  9, 13),
	MAKE_ROW4( 2,  6, 10, 14),
	MAKE_ROW4( 3,  7, 11, 15),

	MAKE_ROW2( 8, 13),
	MAKE_ROW3( 4,  9, 14),
	MAKE_ROW4( 0,  5, 10, 15),
	MAKE_ROW3( 1,  6, 11),
	MAKE_ROW2( 2,  7),

	MAKE_ROW2( 4,  1),
	MAKE_ROW3( 8,  5,  2),
	MAKE_ROW4(12,  9,  6,  3),
	MAKE_ROW3(13, 10,  7),
	MAKE_ROW2(14, 11),
};
const int nrows = 18;

vector<u32> best_grids;


// next higher number with same number of 1's in binary
u32 next_popcount(u32 n)
{
    u32 c = (n & -n);
    u32 r = n+c;
    return (((r ^ n) >> 2) / c) | r;
}
// Returns first integer with exactly n bits set
u32 init_popcount(int n) { return (1 << n) - 1; }
int get_popcount(u32 b)
{
	int n = 0;
	for (u32 x = b; x; ClrFS(x)) ++n;
	return n;
}


int get_even_rows(u32 b)
{
	int ans = 0;
	for (int i = 0; i < nrows; ++i) {
		u32 masked = b & row_masks[i];
		int cnt = get_popcount(masked);

		if (cnt > 0 && cnt % 2 == 0) ++ans;
	}
	return ans;
}

void prepare()
{
	// find all the optimal grids (with 16 rows) in one pass
	u32 top = 1 << 16;
	for (u32 b = init_popcount(10); b < top; b = next_popcount(b)) {
		int r = get_even_rows(b);
		if (r == 16) best_grids.push_back(b);
	}
}

int solve()
{
	u32 b = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j) {
			int k = i*4 + j;
			if (grid[i][j] == '*') b |= 1 << k;
		}

	int ans = 16;
	For (vector<u32>, g, best_grids) {
		int moves = get_popcount(b ^ *g) / 2;

		if (moves < ans) ans = moves;
	}
	return ans;
}

int main()
{
	prepare();

	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		for (int i = 0; i < 4; ++i) scanf("%s", grid[i]);
		printf("Case %d: %d\n", ++ncase, solve());
	}

	return 0;
}
