#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 100


int T;
char board[5][6];


void test_case(bool crit = false)
{
	for (int i = 0; i < 5; ++i)
		for (int j = 0; j < 5; ++j)
			board[i][j] = '.';

	int n = crit ? 9 : rand() % 9 + 1;
	while (n--) {
		int i, j;
		do {
			i = rand() % 5;
			j = rand() % 5;
		} while (board[i][j] == '*');
		board[i][j] = '*';
	}

	puts("");
	for (int i = 0; i < 5; ++i) printf("%s\n", board[i]);

	--T;
}

void test_fixed(const char *b)
{
	int p = 0;
	puts("");
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j)
			putchar(b[p++]);
		puts("");
	}
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed("....." "....." "..*.." "....." ".....");
	test_fixed("....." "....." ".*..." "....." ".....");
	test_fixed("....." "....." "*...." "....." ".....");
	test_fixed("*...*" "....." "....." "....." "*...*");
	test_fixed("....." ".***." ".***." ".***." ".....");
	test_fixed("..*.." "*.*.*" "*..**" "*...*" ".....");

	for (int i = 0; i < 10; ++i) test_case(true);

	while (T) test_case();

	return 0;
}
