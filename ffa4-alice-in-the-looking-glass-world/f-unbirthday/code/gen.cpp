#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 80000
#define MAXP 10000000

void test_case()
{
    int P = rand() % MAXP + 1;

    if (rand() % 50 == 0)
        P = rand() % 1000 + 1;

    printf("%d\n", P);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 1; i <= 100; ++i) {
        printf("%d\n", i);
        --T;
    }

    printf("%d\n", MAXP); --T;

    while (T--) test_case();

    return 0;
}
