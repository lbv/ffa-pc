#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;


#define MAXT 1000
#define MAXN 20

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


int T;

int petals[MAXN];
bool plucked[MAXN];


void test_case(bool crit = false)
{
	int N = crit ? MAXN : rand() % (MAXN - 2) + 3;
	int M = rand() % (N-1) + 1;

	printf("%d %d\n", N, M);

	Clr(plucked);
	for (int i = 0; i < M; ++i) {
		int p;
		do {
			p = rand() % N + 1;
		} while (plucked[p]);
		plucked[p] = true;
		petals[i] = p;
	}

	sort(petals, petals + M);
	for (int i = 0; i < M; ++i) {
		if (i > 0) putchar(' ');
		printf("%d", petals[i]);
	}
	puts("");

	--T;
}

void test_fixed(int n, int m, const char *p)
{
	printf("%d %d\n%s\n", n, m, p);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(3, 1, "1");
	test_fixed(3, 1, "2");
	test_fixed(3, 1, "3");
	test_fixed(3, 2, "1 2");
	test_fixed(3, 2, "1 3");
	test_fixed(4, 2, "1 4");
	test_fixed(11, 2, "1 5");
	test_fixed(9, 3, "2 4 8");
	test_fixed(20, 19, "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19");

	for (int i = 0; i < 10; ++i) test_case(true);

	while (T) test_case();

	return 0;
}
