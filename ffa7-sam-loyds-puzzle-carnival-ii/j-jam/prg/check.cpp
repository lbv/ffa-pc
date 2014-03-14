#include <cassert>
#include <cstdio>

#define MAXT 5000
#define MAXN 15
#define MAXJ 100.0


int S, M, L;
double J;

int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);

		for (int i = 0; i < 3; ++i) {

			scanf("%d%d%d%lf", &S, &M, &L, &J);
			assert(0 <= S && S <= MAXN);
			assert(0 <= M && M <= MAXN);
			assert(0 <= L && L <= MAXN);
			assert(0 < J && J <= MAXJ);
		}
	}

	puts("OK");

	return 0;
}
