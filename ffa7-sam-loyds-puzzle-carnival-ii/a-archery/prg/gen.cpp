#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;


#define MAXT 500
#define MAXN 50
#define MAXS 300

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


bool vis[MAXS + 1];
int P[MAXN];

void test_case(bool crit = false)
{
	int N, S;

	N = crit ? MAXN : rand() % MAXN + 1;
	S = crit ? MAXS : rand() % (MAXS - (N-1)) + N;

	printf("%d %d\n", N, S);

	Clr(vis);
	for (int i = 0; i < N; ++i) {
		int p;
		do {
			p = rand() % S + 1;
		} while (vis[p]);
		vis[p] = true;

		P[i] = p;
	}

	sort(P, P + N);

	for (int i = 0; i < N; ++i) {
		if (i > 0) putchar(' ');
		printf("%d", P[i]);
	}
	puts("");
}

int main()
{
	srand(time(NULL));

	int T = MAXT;
	printf("%d\n", T);

	printf(
"1 100\n"
"1\n"); --T;

	printf(
"1 1\n"
"1\n"); --T;

	printf(
"3 30\n"
"5 15 25\n"); --T;

	printf(
"3 5\n"
"2 3 5\n"); --T;

	printf(
"2 7\n"
"3 5\n"); --T;

	printf(
"1 299\n"
"2\n"); --T;

	for (int i = 0; i < 10; ++i) {
		test_case(true);
		--T;
	}

	while (T--) test_case();

	return 0;
}
