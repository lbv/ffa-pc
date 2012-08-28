#include <cassert>
#include <cstdio>

#define MAXT 10000
#define MAXA 1000000000000000ULL

typedef unsigned long long u64;

u64 A, B;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%llu%llu", &A, &B);

        assert(1 <= A && A <= MAXA);
        assert(1 <= B && B <= MAXA);

        u64 ans = 3*A - B;

        assert(3*A > 2*B);
        assert(ans > A && ans > B);
    }

    puts("OK");

    return 0;
}
