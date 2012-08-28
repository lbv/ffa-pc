#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXN 1000000000000000000LL

typedef long long i64;

i64 N;


int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%lld", &N);

        assert(0 <= N && N <= MAXN);
    }

    puts("OK");

    return 0;
}
