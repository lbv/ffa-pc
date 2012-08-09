#include <cmath>
#include <cstdio>

const double Pi = acos(0.0) * 2;
int r, h;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &r, &h);

        double cake = Pi*r*r*h;

        printf("Case %d: %.2lf %.2lf\n", ++ncase,
               cake * 2.0 / 3.0, cake / 3.0);
    }

    return 0;
}
