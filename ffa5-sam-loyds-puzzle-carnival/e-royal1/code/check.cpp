#include <cassert>
#include <cstdio>

#define MAXT 20000
#define MAXN 1000000000

int N;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d", &N);

        assert(0 <= N && N <= MAXN);
    }

    puts("OK");

    return 0;
}
