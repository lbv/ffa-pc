#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 20000
#define MAXN 50
#define MAXS 10000

void test_case()
{
    int N = rand() % (MAXN - 2) + 3;
    int S = rand() % MAXS + 1;

    printf("%d %d\n", N, S);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("3 1"); --T;
    puts("3 13"); --T;
    puts("50 1"); --T;
    puts("50 10000"); --T;
    puts("3 10000"); --T;

    while (T--) test_case();

    return 0;
}
