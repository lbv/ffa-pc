#include <cassert>
#include <cstdio>


#define MAXT 1000

char grid[4][5];



int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);

		for (int i = 0; i < 4; ++i) scanf("%s", grid[i]);

		int coins = 0;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j) {
				char cell = grid[i][j];
				assert(cell == '.' || cell == '*');

				if (cell == '*') ++coins;
			}
		assert(coins == 10);
	}

	puts("OK");

	return 0;
}
