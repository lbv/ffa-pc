#include <cstdio>


int H1, S, H2;


template<typename T>
T gcd(T a, T b) { for (T c = a%b; c != 0; a=b,b=c,c=a%b); return b; }

void solve()
{
	int p = S * (H2-1);
	int q = H1-1;

	int g = gcd(p, q);
	p /= g;
	q /= g;

	if (q == 1)
		printf("%d\n", p);
	else if (p > q) {
		int n = p / q;
		p %= q;
		printf("%d %d/%d\n", n, p, q);
	}
	else
		printf("%d/%d\n", p, q);
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d%d", &H1, &S, &H2);
		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
