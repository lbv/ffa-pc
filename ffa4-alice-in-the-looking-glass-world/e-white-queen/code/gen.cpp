#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXN 1000000

void test_case()
{
    int n = rand() % MAXN + 1;
    int k = rand() % MAXN + 1;

    if (rand() % 4 != 0)
        k = rand() % n + 1;

    printf("%d %d\n", n, k);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("2 3"); --T;
    puts("2 4"); --T;
    puts("3 7"); --T;
    puts("1 1"); --T;
    puts("2 2"); --T;
    puts("3 3"); --T;
    puts("4 4"); --T;
    puts("5 5"); --T;
    puts("1000000 1000000"); --T;
    puts("1000000 1"); --T;
    puts("8 3"); --T;
    puts("42 2"); --T;

    while (T--) test_case();

    return 0;
}
