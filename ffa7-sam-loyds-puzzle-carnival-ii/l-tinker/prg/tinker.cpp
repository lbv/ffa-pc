#include <cmath>
#include <cstdio>


#define GALLON 282.0


const double pi = acos(-1.0);


int D, V;


double solve()
{
	return sqrt(3.0 * GALLON * V / (7 * pi * D)) * 4;
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d", &D, &V);
		printf("Case %d: %.3lf\n", ++ncase, solve());
	}

	return 0;
}
