#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXA 10000000


int A;


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d", &A);
		assert(1 <= A && A <= MAXA);
	}

	puts("OK");

	return 0;
}
