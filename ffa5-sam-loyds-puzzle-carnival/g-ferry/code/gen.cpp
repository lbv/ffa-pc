#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXA 1000000000000000ULL

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
    u64 A = rand_u64() % (MAXA - 1) + 2;
    u64 B;

    do {
        B = rand_u64() % (A*3/2) + 1;
    } while (B > MAXA);

    if (rand() % 20 == 0) {
        A = rand() % 1000 + 2;
        B = rand() % (A*3/2) + 1;
    }

    if (rand() % 50 == 0) {
        A = rand() % 1000000 + 2;
        B = rand() % (A*3/2) + 1;
    }

    printf("%llu %llu\n", A, B);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("1 1"); --T;
    puts("2 1"); --T;
    puts("3 4"); --T;

    while (T--) test_case();

    return 0;
}
