#include <cassert>
#include <cstdio>


#define MAXT 5000
#define MAXN 20


int petals[MAXN];
int N, M;


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d%d", &N, &M);
		assert(3 <= N && N <= MAXN);
		assert(1 <= M && M < N);

		for (int i = 0; i < M; ++i) {
			scanf("%d", &petals[i]);
			assert(1 <= petals[i] && petals[i] <= N);
			if (i > 0)
				assert(petals[i] > petals[i-1]);
		}
	}

	puts("OK");

	return 0;
}
