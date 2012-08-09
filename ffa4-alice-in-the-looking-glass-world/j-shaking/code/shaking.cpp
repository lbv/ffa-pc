#include <cmath>
#include <cstdio>

const double Pi_2 = acos(0);
double t;

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

    int ncase = 0;
    while (T--) {
        scanf("%lf", &t);

        printf("Case %d: ", ++ncase);

        if (yp(t) > 0)
            puts("forward");
        else
            puts("backward");
    }

    return 0;
}
