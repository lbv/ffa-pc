#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 30000
#define MAXN 500000000000LL

typedef long long i64;

i64 rand_i64()
{
    i64 r = rand();
    r <<= 32;
    r |= rand();
    return r;
}

void test_case()
{
    i64 N = rand_i64() % (MAXN - 2) + 3;

    if (rand() % 50 == 0)
        N = rand() % 10000 + 3;

    if (rand() % 13 == 0) {
        N = rand() % (1000000 - 2) + 2;
        N = N * (N+1) / 2;
    }

    printf("%lld\n", N);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("%lld\n", MAXN); --T;
    puts("3"); --T;
    puts("4"); --T;
    puts("5"); --T;
    puts("6"); --T;
    puts("9"); --T;
    puts("10"); --T;
    puts("42"); --T;
    puts("105"); --T;
    puts("1000003"); --T;

    while (T--) test_case();

    return 0;
}
