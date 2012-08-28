#include <cassert>
#include <cstdio>

#define MAXT 20000
#define MAXH 10000
#define MAXD 1000

int H, D;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &H, &D);

        assert(1 <= H && H <= MAXH);
        assert(2 <= D && D <= MAXD);
    }

    puts("OK");

    return 0;
}
