#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 5000


int T;


void test_case()
{
	int H1 = rand() % 11 + 2;
	int S = rand() % 59 + 1;
	int H2;

	do {
		H2 = rand() % 11 + 2;
	} while (H1 == H2);

	printf("%d %d %d\n", H1, S, H2);
	--T;
}

void test_fixed(int H1, int S, int H2)
{
	printf("%d %d %d\n", H1, S, H2);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(2, 1, 3);
	test_fixed(3, 1, 2);
	test_fixed(12, 1, 2);
	test_fixed(2, 59, 3);
	test_fixed(12, 59, 2);
	test_fixed(12, 59, 11);

	while (T) test_case();

	return 0;
}
