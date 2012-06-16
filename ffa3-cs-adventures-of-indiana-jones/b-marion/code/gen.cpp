#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 1000
#define MAXN 100
#define MAXI 1023

void test_case()
{
    int N = rand() % MAXN + 1;
    printf("%d\n", N);

    int grundy = 0;
    int x;

    for (int i = 1; i <= N; ++i) {
        x = rand() % MAXI + 1;

        if (i == N && grundy > 0 && rand() % 5 == 0)
            x = grundy;

        printf("%s%d", i == 1 ? "" : " ", x);
        grundy ^= (x % (i + 1));
    }
    putchar('\n');
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("1\n1\n"); --T;
    printf("1\n2\n"); --T;
    printf("1\n3\n"); --T;
    printf("1\n4\n"); --T;
    printf("1\n999\n"); --T;
    printf("1\n1000\n"); --T;
    printf("2\n1 1\n"); --T;
    printf("2\n100 100\n"); --T;

    while (T--) test_case();

    return 0;
}
