#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXP 1000000000

int p, q;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d/%d", &p, &q);

        assert(1 <= p && p < q && q <= MAXP);
    }

    puts("OK");

    return 0;
}
