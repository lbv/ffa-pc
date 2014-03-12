#include <cassert>
#include <cstdio>

#define MAXT 3000
#define MAXL 100000


int L;


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d", &L);
		assert(1 <= L && L <= MAXL);
	}

	puts("OK");

	return 0;
}
