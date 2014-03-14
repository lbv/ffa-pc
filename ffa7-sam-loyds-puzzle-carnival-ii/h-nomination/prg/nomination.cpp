#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stack>
using namespace std;


#define GetFS(b) ((b) & -(b))
#define ClrFS(b) (b &= ~GetFS(b))
static const int m37pos[] = {
	32,  0,  1, 26,  2, 23, 27,  0,  3,
	16, 24, 30, 28, 11,  0, 13,  4,  7,
	17,  0, 25, 22, 31, 15, 29, 10, 12,
	 6,  0, 21, 14,  9,  5, 20,  8, 19, 18
};
#define Ctz(x) (m37pos[(x) % 37])

#define Pos(i,j) ((i)*5 + (j))
#define Bit(i,j) (1 << Pos(i,j))

#define Row(x) ((x)/5)
#define Col(x) ((x)%5)

#define INF 1000


typedef unsigned char uch;
typedef unsigned int u32;
typedef unsigned long long u64;


const int moves[8][2] = {
	{ -1,  0 },
	{ -1,  1 },
	{  0,  1 },
	{  1,  1 },
	{  1,  0 },
	{  1, -1 },
	{  0, -1 },
	{ -1, -1 }
};

struct Board {
	u32 b;	   // bitmask of board
	int n;	   // number of pieces
	int p[9];  // indices of pieces
	int _h;    // cache of heuristics value

	int nxt_p;	// next piece to move
	int nxt_m;	// next move to make

	Board() {}
	Board(u32 B): b(B) { init(); }

	void calc_h() {
		if (n == 1)
			_h = distance(p[0], Pos(2, 2));
		else
			_h = n - 1;
	}

	int distance(int a, int b) {
		return max(abs(Row(a) - Row(b)), abs(Col(a) - Col(b)));
	}

	int h() { return _h; }

	void init() {
		n = 0;
		for (u32 x = b; x; ClrFS(x))
			p[n++] = Ctz(GetFS(x));
		calc_h();
	}

	bool is_solution() {
		return n == 1 && p[0] == Pos(2, 2);
	}

	bool move_piece(int pi, int mi, u32 &board) {
		int dr = moves[mi][0];
		int dc = moves[mi][1];

		int r = Row(p[pi]);
		int c = Col(p[pi]);

		int nr = r + dr;
		int nc = c + dc;
		if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) return false;

		u32 piece = 1 << p[pi];

		if ((b & Bit(nr, nc)) == 0) {
			board = (b & ~piece) | Bit(nr, nc);
			return true;
		}

		int nr2 = nr + dr;
		int nc2 = nc + dc;
		if (nr2 < 0 || nr2 >= 5 || nc2 < 0 || nc2 >= 5) return false;

		if (b & Bit(nr2, nc2)) return false;

		board = (b & ~piece);
		board &= ~Bit(nr, nc);
		board |= Bit(nr2, nc2);
		return true;
	}

	bool next(Board &child, int &dist, int &delta) {
		u32 new_board = 0;
		bool can_move = false;

		while (nxt_p < n && !can_move) {
			can_move = move_piece(nxt_p, nxt_m, new_board);

			if (++nxt_m >= 8) {
				nxt_m = 0;
				++nxt_p;
			}
		}

		if (! can_move) return false;

		child.b = new_board;
		child.init();

		dist = 1;
		delta = b;

		return true;
	}

	void reset() { nxt_m = nxt_p = 0; }
};


//
// IDA*
//
typedef Board NodeT;
typedef int DeltaT;

// Depth limited search
bool ida_dls(NodeT &node, int depth, int g, int &nxt, stack<DeltaT> &st)
{
	if (g == depth) return node.is_solution();

	NodeT child;
	int dist;
	DeltaT delta;
	for (node.reset(); node.next(child, dist, delta);) {
		int f = g + dist + child.h();
		if (f > depth && f < nxt) nxt = f;
		if (f <= depth	&& ida_dls(child, depth, g + 1, nxt, st)) {
			st.push(delta);
			return true;
		}
	}
	return false;
}

bool ida_star(NodeT &root, int limit, stack<DeltaT> &st)
{

	for (int depth = root.h(); depth <= limit;) {
		int next_depth = INF;
		if (ida_dls(root, depth, 0, next_depth, st)) return true;
		if (next_depth == INF) return false;
		depth = next_depth;
	}
	return false;
}


char in_board[5][6];


void print_board(u32 b)
{
	puts("");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			putchar((b & Bit(i,j)) ? '*' : '.');
		}
		puts("");
	}
}

int solve()
{
	u32 b = 0;

	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			if (in_board[i][j] == '*')
				b |= 1 << (i*5 + j);

	Board root(b);
	stack<int> st;
	ida_star(root, INF, st);

	return st.size();
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		for (int i = 0; i < 5; ++i) scanf("%s", in_board[i]);
		printf("Case %d: %d\n", ++ncase, solve());
	}

	return 0;
}
