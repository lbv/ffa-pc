#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 100


int T;


void test_case(bool crit = false)
{
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	while (T) test_case();

	return 0;
}
