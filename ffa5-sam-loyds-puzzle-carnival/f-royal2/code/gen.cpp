#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 5000
#define MAXL 999999

void test_case()
{
    int L = rand() % MAXL + 1;

    if (rand() % 10 == 0)
        L = rand() % 1000 + 1;

    printf("%d\n", L);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 1; i <= 10; ++i) {
        printf("%d\n%d\n", i, MAXL + 1 - i);
        T -= 2;
    }

    while (T--) test_case();

    return 0;
}
