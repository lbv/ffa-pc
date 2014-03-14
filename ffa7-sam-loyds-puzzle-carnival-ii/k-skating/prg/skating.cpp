#include <cstdio>


double r, t;
double J, M;


void solve()
{
    J = t / (r - 1);
    M = J + t;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%lf%lf", &r, &t);
        solve();
        printf("Case %d: %.3lf %.3lf\n", ++ncase, J, M);
    }

    return 0;
}
