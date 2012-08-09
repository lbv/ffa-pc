#include <cassert>
#include <cstdio>


#define MAXT 30000
#define MAXN 500000000000LL

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

        assert(3 <= N && N <= MAXN);
    }

    puts("OK");

    return 0;
}
