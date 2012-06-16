#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 50
#define MAXN 10000
#define MAXM 5000

void test_case()
{
    int N = rand() % MAXN + 1;
    int M;

    if (rand() % 3 == 0)
        M = rand() % MAXM + 1;
    else
        M = rand() % (MAXM - N/2) + N/2 + 1;

    printf("%d %d\n", N, M);
    while (M--) {
        int t = rand() % 3 + 1;
        int A = rand() % N + 1;
        int B = rand() % N + 1;

        printf("%d %d %d\n", t, A, B);
    }
}

int main()
{
    srand(time(NULL));
    int T = MAXT;
    printf("%d\n", T);

    printf("1 1\n1 1 1\n"); --T;
    printf("1 1\n2 1 1\n"); --T;
    printf("1 1\n3 1 1\n"); --T;
    printf("10000 1\n2 1 10000\n"); --T;

    while (T--) test_case();
    return 0;
}
