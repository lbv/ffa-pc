#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 100
#define MAXN 1000

void test_case()
{
    int N = rand() % MAXN + 1;
    double p = rand() % 101;
    p /= 100.0;

    printf("%d %.2lf\n", N, p);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("1 1.00\n"); --T;
    printf("1 0.00\n"); --T;
    printf("1000 1.00\n"); --T;
    printf("1000 0.00\n"); --T;

    while (T--) test_case();

    return 0;
}
