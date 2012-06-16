#include <cassert>
#include <cmath>
#include <cstdio>

#define MAXT 100
#define MAXN 100
#define MAXR 100.0
#define MAXM 200.0

int T, N;
double R;
double M, Cx, Cy;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%lf", &N, &R);
        assert(2 <= N && N <= MAXN);
        assert(0.0 < R && R <= MAXR);

        M = Cx = Cy = 0;
        for (int i = 0; i < N; ++i) {
            double m, x, y;
            scanf("%lf%lf%lf", &m, &x, &y);
            assert(0.0 < m && m <= MAXM);
            assert(sqrt(x*x + y*y) <= R);

            M += m;
            Cx += m*x;
            Cy += m*y;
        }
        Cx /= M;
        Cy /= M;

        R /= 10.0;

        double Cr = sqrt(Cx*Cx + Cy*Cy);
        assert(fabs(Cr - R) > 1e-4);

        bool safe = Cr <= R;

        printf("Case %d: %s\n", ++ncase, safe ? "yes" : "no");
    }

    return 0;
}
