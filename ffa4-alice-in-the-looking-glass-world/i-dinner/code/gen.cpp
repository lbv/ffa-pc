#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 200
#define MAXN 50000

void test_case()
{
    int N = rand() % (MAXN - 2) + 3;
    printf("%d\n", N);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 3; i <= 20; ++i) {
        printf("%d\n", i);
        --T;
    }

    printf("%d\n", MAXN); --T;
    while (T--) test_case();

    return 0;
}
