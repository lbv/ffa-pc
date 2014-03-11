#include <cassert>
#include <cstdio>

#define MAXT 500
#define MAXN 50
#define MAXS 300

int P[MAXN];
int N, S;

int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d%d", &N, &S);
		assert(1 <= N && N <= MAXN);
		assert(1 <= S && S <= MAXS);

		for (int i = 0; i < N; ++i) {
			scanf("%d", &P[i]);
			assert(1 <= P[i] && P[i] <= S);
			if (i > 0) {
				assert(P[i-1] < P[i]);
			}
		}
	}

	puts("OK");

	return 0;
}
