#include <cstdio>


int W[10];
int a, b, c, d, e;


void solve()
{
	int total = 0;
	for (int i = 0; i < 10; ++i) total += W[i];
	total /= 4;

	c = total - W[0] - W[9];
	a = W[1] - c;
	e = W[8] - c;

	b = W[0] - a;
	d = W[9] - e;
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		for (int i = 0; i < 10; ++i) scanf("%d", &W[i]);

		solve();
		printf("Case %d: %d %d %d %d %d\n", ++ncase, a, b, c, d, e);
	}

	return 0;
}
