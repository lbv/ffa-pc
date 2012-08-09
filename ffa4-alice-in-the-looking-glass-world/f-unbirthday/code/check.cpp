#include <cassert>
#include <cstdio>

#define MAXT 100000
#define MAXP 10000000

int P;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d", &P);

        assert(1 <= P && P <= MAXP);
    }

    puts("OK");

    return 0;
}
