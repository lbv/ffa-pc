#include <cmath>
#include <cstdio>


const double pi_4 = acos(-1.0) * 4.0;


double D, N;



double solve()
{
	return pi_4 * D / (N-1);
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%lf%lf", &D, &N);
		printf("Case %d: %.3lf\n", ++ncase, solve());
	}

	return 0;
}
