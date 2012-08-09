#include <cstdio>
#include <cstdlib>
#include <ctime>


#define MAXT 50000
#define MAXR 500
#define MAXH 500


void test_case()
{
    int r = rand() % MAXR + 1;
    int h = rand() % MAXH + 1;

    printf("%d %d\n", r, h);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int r = 1; r <= 10; ++r)
        for (int h = 1; h <= 10; ++h) {
            printf("%d %d\n", r, h);
            --T;
        }

    printf("%d %d\n", MAXR, MAXH); --T;
    puts("1 500"); --T;
    puts("500 1"); --T;
    puts("10 10"); --T;
    puts("10 10"); --T;
    puts("13 27"); --T;
    puts("10 10"); --T;
    puts("13 27"); --T;

    while (T--) test_case();

    return 0;
}
