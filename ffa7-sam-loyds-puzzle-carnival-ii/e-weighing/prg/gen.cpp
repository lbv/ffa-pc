#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 3000
#define MINW 50
#define MAXW 200


int T;
int W[10];
int w[5];


void create_weights()
{
	int k = 0;
	for (int i = 1; i < 5; ++i)
		for (int j = 0; j < i; ++j)
			W[k++] = w[i] + w[j];

	sort(W, W + k);
	for (int i = 0; i < 10; ++i) {
		if (i > 0) putchar(' ');
		printf("%d", W[i]);
	}
	puts("");
}

void test_case(int maxw = MAXW)
{
	for (int i = 0; i < 5; ++i)
		w[i] = rand() % (maxw - (MINW - 1)) + MINW;

	create_weights();
	--T;
}

void test_fixed(int a, int b, int c, int d, int e)
{
	w[0] = a;
	w[1] = b;
	w[2] = c;
	w[3] = d;
	w[4] = e;
	create_weights();
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed(MINW, MINW, MINW, MINW, MINW);
	test_fixed(MAXW, MAXW, MAXW, MAXW, MAXW);
	test_fixed(100, 101, 102, 103, 104);

	for (int i = 0; i < 100; ++i)
		test_case(80);

	while (T) test_case();

	return 0;
}
