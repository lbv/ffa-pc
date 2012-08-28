#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXB 10000

void test_case()
{
    int b = rand() % (MAXB - 1) + 2;
    int a = rand() % (b - 1) + 1;

    int d = rand() % (MAXB - 1) + 2;
    int c = rand() % (d - 1) + 1;

    if (rand() % 10 == 0) {
        d = rand() % 100 + 10;
        b = d * (rand() % 90 + 1);
        a = b - (rand() % 9 + 1);
        do {
            c = (b-a) * (rand() % (d / (b-a)) + 1);
        } while( c < 1 || c >= d);
    }

    printf("%d/%d %d/%d\n", a, b, c, d);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("4/5 2/5"); --T;
    puts("1/2 1/2"); --T;
    puts("1/2 1/10000"); --T;
    puts("1/2 9999/10000"); --T;
    puts("9999/10000 9999/10000"); --T;
    puts("9999/10000 1/2"); --T;

    while (T--) test_case();

    return 0;
}
