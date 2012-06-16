#include <cassert>
#include <cmath>
#include <cstdio>

#define MAXT 2000
#define MAXDIST 1000.0
#define MAXV 100.0
#define MAXA 10.0

double I, E, V, A;
double Ti;  // time of Indy to reach the exit
double Tb;  // time of the boulder to reach to exit

int main()
{
    int T;
    scanf("%d", &T);
    assert(0 < T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%lf%lf%lf%lf", &I, &E, &V, &A);
        assert(0 <= I && I <= E && E <= MAXDIST);
        assert(0 < V && V <= MAXV);
        assert(0 < A && A <= MAXA);

        Ti = (E-I) / V;
        Tb = sqrt(2*E / A);

        if (Tb < Ti)
            printf("Case %d: Indy can't escape\n", ++ncase);
        else
            printf("Case %d: Indy escapes by %.1lf s\n", ++ncase, Tb - Ti);
    }

    return 0;
}
