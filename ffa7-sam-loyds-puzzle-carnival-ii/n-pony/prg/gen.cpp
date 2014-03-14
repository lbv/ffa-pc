#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 1000
#define MAXD 1000
#define MIND 300
#define MAXN 1000
#define MINN 101


int T;


void test_case()
{
	int D = rand() % (MAXD - (MIND-1)) + MIND;
	int N = rand() % (MAXN - (MINN-1)) + MINN;

	printf("%.2lf %.2lf\n", 1.0*D/100, 1.0*N/100);
	--T;
}

void test_fixed(double d, double n)
{
	printf("%.2lf %.2lf\n", d, n);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(3.0, 1.01);
	test_fixed(10.0, 1.01);
	test_fixed(10.0, 10.0);
	test_fixed(3.0, 10.0);

	while (T) test_case();

	return 0;
}
