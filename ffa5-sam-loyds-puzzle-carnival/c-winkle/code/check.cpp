#include <cassert>
#include <cstdio>

#define MAXT 3000
#define MAXN 100

int N, K;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d", &N, &K);

        assert(1 <= N && N <= MAXN);
        assert(0 <= K && K < N);

        while (K--) {
            int pin;
            scanf("%d", &pin);

            assert(1 <= pin && pin <= N);
        }
    }

    puts("OK");

    return 0;
}
