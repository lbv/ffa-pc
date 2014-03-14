#include <cassert>
#include <cstdio>

#define MAXT 1000
#define MAXD 50
#define MAXV 100


int D, V;


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d%d", &D, &V);
		assert(1 <= D && D <= MAXD);
		assert(1 <= V && V <= MAXV);
	}

	puts("OK");

	return 0;
}
