#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 1000


int T;

char grid[4][5];


void print_grid()
{
	puts("");
	for (int i = 0; i < 4; ++i)
		printf("%s\n", grid[i]);
}

void test_case(bool crit = false)
{
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			grid[i][j] = '.';

	for (int k = 0; k < 10; ++k) {
		int i, j;

		do {
			i = rand() % 4;
			j = rand() % 4;
		} while (grid[i][j] == '*');
		grid[i][j] = '*';
	}

	print_grid();
	--T;
}

void test_fixed(const char *g)
{
	int k = 0;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			grid[i][j] = g[k++];

	print_grid();
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(".**.****..***.*.");
	test_fixed(".*.***..****.**.");
	test_fixed("*.*...******.**.");
	test_fixed(".**.******...*.*");

	test_fixed("*.*.****..***.*.");

	while (T) test_case();

	return 0;
}
