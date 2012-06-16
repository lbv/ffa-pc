#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#define MAXT 100
#define MAXN 100

// Constants multiplied by 100 to provide for decimal digits
#define MAXR 10000
#define MAXM 20000

typedef vector<double> DV;

const double Pi = acos(0.0) * 2;

DV ms;
DV xs;
DV ys;
int N;
double R;

bool test_case()
{
    N = rand() % (MAXN - 1) + 2;
    int iR = rand() % MAXR + 1;

    R = iR;
    R /= 100.0;

    double M = 0.0;
    double Cx = 0.0;
    double Cy = 0.0;

    ms.clear();
    xs.clear();
    ys.clear();
    for (int i = 0; i < N; ++i) {
        double m = rand() % (MAXM) + 1;
        m /= 100.0;

        M += m;

        double r = rand() % iR;
        r /= 100.0;

        if (rand() % 2 == 0)
            r /= 10.0;

        double a = Pi * (180.0 / (rand() % 360));
        double x = cos(a) * r;
        double y = sin(a) * r;

        Cx += x * m;
        Cy += y * m;

        ms.push_back(m);
        xs.push_back(x);
        ys.push_back(y);
    }

    double D = sqrt(Cx*Cx + Cy*Cy);
    return fabs(D - R /10) > 1e-4;
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("\n2 100.00\n200.00 -100.00 0.00\n200.00 100.00 0.00\n"); --T;
    printf("\n2 100.00\n0.01 10.01 0.00\n0.01 10.01 0.00\n"); --T;
    printf("\n2 0.01\n0.01 0.00 0.01\n0.01 0.00 -0.01\n"); --T;

    while (T) {
        if (! test_case()) continue;

        --T;
        printf("\n%d %.2lf\n", N, R);

        for (int i = 0; i < N; ++i)
            printf("%.2lf %.2lf %.2lf\n", ms[i], xs[i], ys[i]);
    }

    return 0;
}
