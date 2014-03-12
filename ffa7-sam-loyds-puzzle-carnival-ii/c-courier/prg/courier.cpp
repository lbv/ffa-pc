#include <cmath>
#include <cstdio>


const double sq2 = sqrt(2);

int D;


double solve()
{
	return D + 2*D/sq2;
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d", &D);
		printf("Case %d: %.2lf\n", ++ncase, solve());
	}

	return 0;
}
