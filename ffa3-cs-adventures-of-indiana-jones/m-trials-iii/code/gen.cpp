#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000

#define MAXCONST 999
#define MAXN     1000000000000000LL

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
    int a = rand() % (MAXCONST + 1);
    int b = rand() % (MAXCONST + 1);
    int x = rand() % (MAXCONST + 1);
    int y = rand() % (MAXCONST + 1);

    u64 n = rand_u64() % MAXN + 1;

    if (rand() % 4 == 0) n = rand() % 1000 + 1;
    if (rand() % 10 == 0) n = rand() % 10 + 1;

    printf("%d %d %d %d %llu\n", a, b, x, y, n);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("0 0 0 0 1\n"); --T;
    printf("3 5 0 0 1\n"); --T;
    printf("3 5 0 0 2\n"); --T;
    printf("3 5 0 0 3\n"); --T;
    printf("5 3 1 1 5\n"); --T;
    printf("0 1 1 1 10\n"); --T;
    printf("999 999 999 999 1000000000000000\n"); --T;

    while (T--) test_case();

    return 0;
}
