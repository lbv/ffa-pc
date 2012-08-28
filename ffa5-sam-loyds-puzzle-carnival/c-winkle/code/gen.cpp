#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>


#define MAXT 3000
#define MAXN 100

#define Zero(v) memset((v), 0, sizeof(v))


bool vis[MAXN];


void test_case()
{
    int N = rand() % MAXN + 1;
    int K = rand() % N;

    printf("%d\n%d", N, K);

    Zero(vis);
    for (int i = 0; i < K; ++i) {
        int p;
        do {
            p = rand() % N;
        } while (vis[p]);
        vis[p] = true;
    }

    for (int i = 0; i < N; ++i)
        if (vis[i])
            printf(" %d", i + 1);
    putchar('\n');
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("1");
    puts("0"); --T;

    puts("100");
    puts("0"); --T;

    puts("2");
    puts("0"); --T;

    puts("2");
    puts("1 1"); --T;

    puts("2");
    puts("1 2"); --T;

    puts("10");
    puts("9 1 2 3 4 5 7 8 9 10"); --T;

    puts("100");
    puts("4 1 10 11 50"); --T;

    while (T--) test_case();

    return 0;
}
