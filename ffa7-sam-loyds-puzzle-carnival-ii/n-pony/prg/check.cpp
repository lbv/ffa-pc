#include <cassert>
#include <cstdio>

#define MAXT 1000
#define MAXD 10.0
#define MAXN 10.0


double D, N;



int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%lf%lf", &D, &N);
		assert(3.0 <= D && D <= MAXD);
		assert(1.0 < N && N <= MAXN);
	}

	puts("OK");

	return 0;
}
