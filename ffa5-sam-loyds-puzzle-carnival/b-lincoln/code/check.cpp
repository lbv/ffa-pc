#include <cassert>
#include <cstdio>

#define MAXT 20000
#define MAXN 50
#define MAXS 10000

int N, S;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &N, &S);

        assert(3 <= N && N <= MAXN);
        assert(1 <= S && S <= MAXS);
    }

    puts("OK");

    return 0;
}
