#include <cassert>
#include <cstdio>

#define MAXT 5000
#define MAXH 12
#define MINH 2
#define MINS 1
#define MAXS 59


int H1, S, H2;


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);
		scanf("%d%d%d", &H1, &S, &H2);
		assert(MINH <= H1 && H1 <= MAXH);
		assert(MINH <= H2 && H2 <= MAXH);
		assert(H1 != H2);
		assert(MINS <= S && S <= MAXS);
	}

	puts("OK");

	return 0;
}
