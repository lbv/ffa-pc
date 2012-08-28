#include <cmath>
#include <cstdio>

const double Pi = acos(0) * 2.0;

int N, S;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &N, &S);

        double a = N;
        a *= S*S;
        a *= 0.25;
        a *= 1.0 / tan(Pi/N);

        printf("Case %d: %.2lf\n", ++ncase, a);
    }

    return 0;
}
