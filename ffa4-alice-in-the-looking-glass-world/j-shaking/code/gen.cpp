#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXVAL 100
#define DELTA (1e-3)
#define DELTAINC (1e-5)
#define EPS (1e-9)

const double Pi_2 = acos(0);

bool eps_equal(double a, double b) { return fabs(a - b) < EPS; }

// first derivative of y(t)
double yp(double t)
{
    return sin(pow(t, Pi_2))/t +
        log(t) * cos(pow(t, Pi_2)) * Pi_2 * pow(t, Pi_2 - 1.0);
}

bool valid(double t)
{
    bool Sgn = yp(t) > 0.0;

    for (double x = t - DELTA, X = t + DELTA; x < X; x += DELTAINC) {
        double deriv = yp(x);
        bool sgn = deriv > 0.0;

        if (eps_equal(deriv, 0.0) || sgn != Sgn) return false;
    }
    return true;
}

void test_case()
{
    double t;

    do {
        int it = rand() % (MAXVAL * 100 - 1) + 1;
        t = it;
        t /= 100.0;
    } while (! valid(t));

    printf("%.2lf\n", t);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("0.01"); --T;
    puts("99.99"); --T;

    while (T--) test_case();

    return 0;
}
