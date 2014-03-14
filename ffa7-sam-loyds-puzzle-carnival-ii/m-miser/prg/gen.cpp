#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;


#define MAXT 2000
#define MAXN 8
#define MAXM 100

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


int T;
int M[MAXN];

bool used[MAXM + 1];


void test_case(bool crit = false)
{
	int N = crit ? MAXN : rand() % MAXN + 1;

	printf("%d\n", N);

	Clr(used);
	for (int i = 0; i < N; ++i) {
		int m;
		do {
			m = rand() % (MAXM - 1) + 2;
		} while (used[m]);

		used[m] = true;
		M[i] = m;
	}
	sort(M, M + N);

	for (int i = 0; i < N; ++i) {
		if (i > 0) putchar(' ');
		printf("%d", M[i]);
	}
	puts("");

	--T;
}


void test_fixed(int N, const char *M)
{
	printf("%d\n%s\n", N, M);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(1, "2");
	test_fixed(1, "100");
	test_fixed(2, "2 4");
	test_fixed(2, "3 5");
	test_fixed(8, "93 94 95 96 97 98 99 100");
	test_fixed(8, "61 67 71 73 79 83 89 97");

	for (int i = 0; i < 200; ++i) test_case(true);

	while (T) test_case();

	return 0;
}
