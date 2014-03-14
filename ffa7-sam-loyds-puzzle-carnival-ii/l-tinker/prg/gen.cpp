#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 1000
#define MAXD 50
#define MAXV 100


int T;


void test_case()
{
	int D = rand() % MAXD + 1;
	int V = rand() % MAXV + 1;

	printf("%d %d\n", D, V);
	--T;
}

void test_fixed(int D, int V)
{
	printf("%d %d\n", D, V);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	for (int i = 0; i < 10; ++i) {
		test_fixed(i+1, i+1);
		test_fixed(MAXD-i, MAXV-i);
		test_fixed(i+1, MAXV-i);
		test_fixed(MAXD-i, i+1);
	}

	while (T) test_case();

	return 0;
}
