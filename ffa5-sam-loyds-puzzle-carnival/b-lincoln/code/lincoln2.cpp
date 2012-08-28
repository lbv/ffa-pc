#include <cmath>
#include <cstdio>

#define EPS (1e-6)

const long double Pi = acosl(-1.0);

int N, S;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &N, &S);

        long double a = N;
        a *= S*S;
        a *= 0.25;
        a /= tanl(Pi/N);

        printf("Case %d: %.2Lf\n", ++ncase, a + EPS);
    }

    return 0;
}
