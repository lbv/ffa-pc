#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 20000
#define MAXH 10000
#define MAXD 1000

void test_case()
{
    int H = rand() % MAXH + 1;
    int D = rand() % (MAXD - 1) + 2;

    if (rand() % 15 == 0)
        H = rand() % 100 + 1;

    printf("%d %d\n", H, D);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("1 2"); --T;
    puts("1 1000"); --T;
    puts("10000 2"); --T;
    puts("10000 1000"); --T;

    while (T--) test_case();

    return 0;
}
