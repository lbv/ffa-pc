#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;


#define MAXT 60
#define MAXN 15
#define MAXM (MAXN*MAXN)

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


int T;

int N, M;
bool used[26];
char nodes[MAXN];
char edges[MAXM][2];
int eorder[MAXM];
bool g[MAXN][MAXN];


void gen_nodes()
{
	Clr(used);
	for (int i = 0; i < N; ++i) {
		if (i > 0) putchar(' ');

		int letter;
		do {
			letter = rand() % 26;
		} while(used[letter]);
		used[letter] = true;

		nodes[i] = 'A' + letter;
		printf("%c", nodes[i]);
	}
	puts("");
}

void test_case(bool crit = false, bool crit_m = false)
{
	N = crit ? MAXN : rand() % (MAXN-1) + 2;

	int MaxM = N * (N-1) / 2;
	M = crit_m ? MaxM : rand() % (MaxM + 1);

	printf("\n%d %d\n", N, M);

	gen_nodes();

	Clr(g);
	while (M--) {
		int u, v;
		do {
			u = rand() % N;
			v = rand() % N;
		} while(u == v || g[u][v]);
		g[u][v] = g[v][u] = true;

		printf("%c %c\n", nodes[u], nodes[v]);
	}

	--T;
}

void test_case_g()
{
	N = rand() % (MAXN-1) + 2;

	int MaxM = N * (N-1) / 2;
	int MinM = N-1;
	M = rand() % (MaxM - (MinM-1)) + MinM;

	printf("\n%d %d\n", N, M);

	gen_nodes();

	Clr(g);
	random_shuffle(nodes + 1, nodes + N - 1);
	int ne = 0;
	for (int i = 1; i < N; ++i) {
		g[i][i-1] = g[i-1][i] = true;
		edges[ne][0] = nodes[i-1];
		edges[ne++][1] = nodes[i];
		--M;
	}

	while (M--) {
		int u, v;
		do {
			u = rand() % N;
			v = rand() % N;
		} while(u == v || g[u][v]);
		g[u][v] = g[v][u] = true;

		edges[ne][0] = nodes[u];
		edges[ne++][1] = nodes[v];
	}

	for (int i = 0; i < ne; ++i) eorder[i] = i;
	random_shuffle(eorder, eorder + ne);

	for (int i = 0; i < ne; ++i) {
		int idx = eorder[i];
		if (rand() % 2 == 0) swap(edges[idx][0], edges[idx][1]);
		printf("%c %c\n", edges[idx][0], edges[idx][1]);
	}

	--T;
}

void test_case_fixed(int n, int m, const char *nodes, const char *edges)
{
	printf("\n%d %d\n%s\n%s", n, m, nodes, edges);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_case_fixed(2, 1, "X Y", "Y X\n");
	test_case_fixed(3, 0, "A B C", "");
	test_case_fixed(5, 5, "A B C D E", "A B\nB C\nC D\nD E\nE A\n");
	test_case_fixed(6, 8, "X A B C D Y",
	"A B\nA D\nA X\nC B\nC D\nX C\nB Y\nD Y\n");

	test_case(true, true);
	for (int i = 0; i < 10; ++i) test_case(true);

	while (T) {
		int r = rand() % 10;

		if (r < 5) test_case_g();
		else test_case();
	}

	return 0;
}
