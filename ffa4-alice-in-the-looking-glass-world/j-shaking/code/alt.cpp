#include <cmath>
#include <cstdio>

#define DELTA (1e-4)

const double Pi_2 = acos(0);
double t;

double y(double t)
{
    return log(t) * sin(pow(t, Pi_2));
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%lf", &t);

        printf("Case %d: ", ++ncase);

        double y1 = y(t - DELTA);
        double y2 = y(t);
        double y3 = y(t + DELTA);

        if (y3 > y2 && y2 > y1)
            puts("forward");
        else
            puts("backward");
    }

    return 0;
}
