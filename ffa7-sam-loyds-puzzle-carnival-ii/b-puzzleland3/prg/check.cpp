#include <cassert>
#include <cstdio>
#include <cstring>

#define MAXT 60
#define MAXN 15

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)
#define Neg(m) Memset(m,-1)


int N, M;
char nodes[MAXN];

int idx[26];
bool g[MAXN][MAXN];


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d%d", &N, &M);
		assert(2 <= N && N <= MAXN);
		assert(0 <= M);

		Neg(idx);
		Clr(g);

		for (int i = 0; i < N; ++i) {
			scanf(" %c", &nodes[i]);
			assert(nodes[i] >= 'A' && nodes[i] <= 'Z');
			idx[nodes[i] - 'A'] = i;
		}

		while (M--) {
			char a, b;
			scanf(" %c %c", &a, &b);
			assert(a >= 'A' && a <= 'Z');
			assert(b >= 'A' && b <= 'Z');

			int u = idx[a - 'A'];
			int v = idx[b - 'A'];

			assert(u >= 0 && v >= 0);

			assert(! g[u][v]);
			assert(! g[v][u]);

			g[u][v] = g[v][u] = true;
		}
	}

	puts("OK");

	return 0;
}
