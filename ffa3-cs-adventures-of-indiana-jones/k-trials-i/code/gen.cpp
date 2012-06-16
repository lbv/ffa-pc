#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXT 1000

// constant multiplied by 100
#define MAXL 100000

void test_case()
{
    int iA = rand() % MAXL + 1;
    int iB = rand() % MAXL + 1;

    int iL = rand() % (min(iA, iB) - 1) + 1;

    double A = iA;
    double B = iB;
    double L = iL;
    A /= 100.0;
    B /= 100.0;
    L /= 100.0;

    double p = sqrt(A*A - L*L);
    double q = sqrt(B*B - L*L);

    double s = L / (q/p + 1);
    double r = L * (q/p) / (q/p + 1);

    fprintf(stderr, "  %lf = %lf = %lf + %lf\n", L, s + r, s, r);

    double h = r*p / L;

    printf("%.2lf %.2lf %.2lf\n", A, B, h);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    while (T--) test_case();

    return 0;
}
