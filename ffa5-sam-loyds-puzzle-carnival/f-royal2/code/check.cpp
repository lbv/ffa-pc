#include <cassert>
#include <cstdio>

#define MAXT 5000
#define MAXL 999999

int L;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d", &L);

        assert(1 <= L && L <= MAXL);
    }

    puts("OK");

    return 0;
}
