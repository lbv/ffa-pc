#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXB 10000

int a, b, c, d;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d/%d %d/%d", &a, &b, &c, &d);

        assert(0 < a && a < b && b <= MAXB);
        assert(0 < c && c < d && d <= MAXB);
    }

    puts("OK");

    return 0;
}
