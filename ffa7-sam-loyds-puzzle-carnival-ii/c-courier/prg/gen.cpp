#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 3000
#define MAXL 100000


int T;


void test_case(int maxl = MAXL)
{
	int L = rand() % maxl + 1;
	printf("%d\n", L);
	--T;
}

void test_fixed(int L)
{
	printf("%d\n", L);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	for (int i = 0; i < 10; ++i) {
		test_fixed(1 + i);
		test_fixed(MAXL - i);
	}

	for (int i = 0; i < 100; ++i) test_case(100);
	for (int i = 0; i < 100; ++i) test_case(1000);

	while (T) test_case();

	return 0;
}
