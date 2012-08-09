#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXN 1000000

int n, k;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &n, &k);

        assert(1 <= n && n <= MAXN);
        assert(1 <= k && k <= MAXN);
    }

    puts("OK");

    return 0;
}
