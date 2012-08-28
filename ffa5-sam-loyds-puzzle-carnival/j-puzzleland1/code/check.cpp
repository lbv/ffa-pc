#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXK 200
#define MINS -2000
#define MAXS 2000

int K, S;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &K, &S);

        assert(1 <= K && K <= MAXK);
        assert(MINS <= S && S <= MAXS);
    }

    puts("OK");

    return 0;
}
