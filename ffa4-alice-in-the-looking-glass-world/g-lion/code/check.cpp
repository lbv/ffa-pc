#include <cassert>
#include <cstdio>

#define MAXT 50000
#define MAXR 500
#define MAXH 500


int r, h;


int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &r, &h);

        assert(1 <= r && r <= MAXR);
        assert(1 <= h && h <= MAXH);
    }

    puts("OK");

    return 0;
}
