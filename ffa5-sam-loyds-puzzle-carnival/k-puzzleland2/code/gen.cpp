#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXN 1000000000000000000LL

typedef unsigned long long u64;

u64 rand_u64()
{
    u64 r = rand();
    r <<= 32;
    r |= rand();
    return r;
}

void test_case()
{
    u64 N = rand_u64() % (MAXN + 1);

    if (rand() % 20 == 0)
        N = rand() % 1000;

    printf("%llu\n", N);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 0; i < 15; ++i) {
        printf("%d\n", i);
        --T;
        printf("%lld\n", MAXN - i);
        --T;
    }


    while (T--) test_case();

    return 0;
}
