#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 20
#define MAXN 1000
#define MAXM 10000
#define MAXD 100
#define MAXW 10000

void test_case()
{
    int N = rand() % (MAXN - 1) + 2;
    int M = rand() % (MAXM - N - 2) + N - 1;

    if (rand() % 15 == 0) N = MAXN, M = MAXM;

    int D = rand() % MAXD + 1;

    printf("\n%d %d %d\n", N, M, D);

    int u, v, w1, w2;
    for (int i = 0; i < N - 1; ++i) {
        w1 = rand() % MAXW + 1;
        w2 = rand() % MAXW + 1;
        printf("%d %d %d %d\n", i, i + 1, w1, w2);
        --M;
    }

    while (M--) {
        do {
            u = rand() % N;
            v = rand() % N;
        } while (u == v);

        w1 = rand() % MAXW + 1;
        w2 = rand() % MAXW + 1;
        printf("%d %d %d %d\n", u, v, w1, w2);
    }
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("\n2 1 1\n1 0 1 1\n"); --T;
    printf("\n2 1 100\n0 1 10000 10000\n"); --T;
    printf("\n3 2 5\n0 1 16 5\n1 2 5 11\n"); --T;

    while (T--) test_case();

    return 0;
}
