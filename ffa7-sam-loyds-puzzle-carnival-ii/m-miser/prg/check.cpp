#include <cassert>
#include <cstdio>

#define MAXT 2000
#define MAXN 8
#define MAXM 100


int N;
int M[MAXN];


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d", &N);
		assert(1 <= N && N <= MAXN);

		for (int i = 0; i < N; ++i) {
			scanf("%d", &M[i]);
			assert(2 <= M[i] && M[i] <= MAXM);

			if (i > 0)
				assert(M[i-1] < M[i]);
		}
	}

	puts("OK");

	return 0;
}
