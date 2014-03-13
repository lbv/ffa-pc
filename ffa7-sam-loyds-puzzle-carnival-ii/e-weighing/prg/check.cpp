#include <cassert>
#include <cstdio>

#define MAXT 3000
#define MINW 100
#define MAXW 400


int W[10];


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);

		for (int i = 0; i < 10; ++i) {
			scanf("%d", &W[i]);
			assert(MINW <= W[i] && W[i] <= MAXW);
			if (i > 0)
				assert(W[i] >= W[i-1]);
		}
	}

	puts("OK");

	return 0;
}
