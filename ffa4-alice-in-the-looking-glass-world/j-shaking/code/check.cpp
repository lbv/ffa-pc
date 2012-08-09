#include <cassert>
#include <cmath>
#include <cstdio>

#define MAXT 10000
#define MAXVAL 100.0
#define DELTA (1e-3)
#define DELTAINC (1e-5)
#define EPS (1e-9)

const double Pi_2 = acos(0.0);

double t;

bool eps_equal(double a, double b) { return fabs(a - b) < EPS; }

// first derivative of y(t)
double yp(double t)
{
    return sin(pow(t, Pi_2))/t +
        log(t) * cos(pow(t, Pi_2)) * Pi_2 * pow(t, Pi_2 - 1.0);
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int cas = 1; cas <= T; ++cas) {
        printf("Testing case %d ..\n", cas);
        scanf("%lf", &t);

        assert(0.0 + EPS < t && t < MAXVAL - EPS);

        bool Sgn = yp(t) > 0.0;

        for (double x = t - DELTA, X = t + DELTA; x < X; x += DELTAINC) {
            double deriv = yp(x);
            bool sgn = deriv > 0.0;

            assert(! eps_equal(deriv, 0.0));
            assert(sgn == Sgn);
        }
    }

    puts("OK");

    return 0;
}
