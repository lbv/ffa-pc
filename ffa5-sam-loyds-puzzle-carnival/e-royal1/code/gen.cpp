#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 20000
#define MAXN 1000000000

void test_case()
{
    int N = rand() % (MAXN + 1);

    if (rand() % 30 == 0)
        N = rand() % 1000;

    printf("%d\n", N);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 0; i <= 20; ++i) {
        printf("%d\n", i);
        --T;
        printf("%d\n", MAXN - i);
        --T;
    }

    while (T--) test_case();

    return 0;
}
