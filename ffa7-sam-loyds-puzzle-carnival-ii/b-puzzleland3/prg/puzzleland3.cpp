#include <cstdio>
#include <cstring>


#define MAXN 15


#define GetFS(b) ((b) & -(b))
#define ClrFS(b) (b &= ~GetFS(b))
static const int m37pos[] = {
    32,  0,  1, 26,  2, 23, 27,  0,  3,
    16, 24, 30, 28, 11,  0, 13,  4,  7,
    17,  0, 25, 22, 31, 15, 29, 10, 12,
     6,  0, 21, 14,  9,  5, 20,  8, 19, 18
};
#define Ctz(x) (m37pos[(x) % 37])

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


typedef unsigned int u32;


int N, M;
char nodes[MAXN];
int idx[26];

bool g[MAXN][MAXN];

char path[MAXN][1 << MAXN][MAXN];
bool valid[MAXN][1 << MAXN];
bool vis[MAXN][1 << MAXN];


void append_path(int v, u32 b, int n)
{
	path[v][b][n-1] = nodes[v];
	valid[v][b] = true;
}

// dp(v, b, n): true if there is a path that ends in {v}, having visited the
//              nodes in bitmask {b}. {n} is the number of nodes in {b}.
bool dp(int v, u32 b, int n)
{
	if (vis[v][b]) return valid[v][b];

	u32 prev = b & ~(1 << v);
	for (u32 x = b; x; ClrFS(x)) {
		int u = Ctz(GetFS(x));

		if (!g[u][v] || !dp(u, prev, n - 1)) continue;

		if (!valid[v][b] || strncmp(path[u][prev], path[v][b], n-1) < 0) {
			strncpy(path[v][b], path[u][prev], n-1);
			append_path(v, b, n);
		}

	}

	vis[v][b] = true;
	return valid[v][b];
}

void solve()
{
	Clr(valid);
	Clr(vis);

	append_path(0, 1, 1);
	vis[0][1] = true;

	u32 bmask = (1 << N) - 1;
	if (dp(N - 1, bmask, N)) {
		for (int i = 0; i < N; ++i)
			putchar(path[N-1][bmask][i]);
			puts("");
	}
	else
		puts("impossible");
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d", &N, &M);

		for (int i = 0; i < N; ++i) {
			scanf(" %c", &nodes[i]);
			idx[nodes[i] - 'A'] = i;
		}

		Clr(g);
		for (int i = 0; i < M; ++i) {
			char u, v;
			scanf(" %c %c", &u, &v);

			int p = idx[u - 'A'];
			int q = idx[v - 'A'];

			g[p][q] = g[q][p] = true;
		}

		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
