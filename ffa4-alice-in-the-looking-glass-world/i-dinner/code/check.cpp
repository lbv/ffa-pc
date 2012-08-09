#include <cassert>
#include <cstdio>

#define MAXT 200
#define MINN 3
#define MAXN 50000

int N;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d", &N);

        assert(MINN <= N && N <= MAXN);
    }

    puts("OK");

    return 0;
}
