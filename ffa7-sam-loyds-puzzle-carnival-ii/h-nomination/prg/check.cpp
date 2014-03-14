#include <cassert>
#include <cstdio>

#define MAXT 100

char board[5][6];


int main()
{
	int T;
	scanf("%d", &T);
	assert(1 <= T && T <= MAXT);

	for (int t = 1; t <= T; ++t) {
		printf("Testing case %d ..\n", t);

		for (int i = 0; i < 5; ++i) scanf("%s", board[i]);

		int cnt = 0;
		for (int i = 0; i < 5; ++i)
			for (int j = 0; j < 5; ++j) {
				char c = board[i][j];
				assert(c == '.' || c == '*');

				if (c == '*') ++cnt;
			}

		assert(1 <= cnt && cnt <= 9);
	}

	puts("OK");

	return 0;
}
