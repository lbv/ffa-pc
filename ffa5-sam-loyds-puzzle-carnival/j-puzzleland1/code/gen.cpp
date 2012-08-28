#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 10000
#define MAXK 200
#define MINS -2000
#define MAXS 2000

const int MaxScore  = MAXS - MINS + 1;

void test_case()
{
    int K = rand() % MAXK + 1;
    int S = rand() % MaxScore + MINS;

    if (rand() % 5 != 0) {
        int hi = K * 3;
        int lo = K * -10;
        int max_score = hi - lo + 1;

        S = rand() % max_score + lo;
    }

    printf("%d %d\n", K, S);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("200 -2000"); --T;
    puts("200 600"); --T;
    puts("200 601"); --T;
    puts("200 2000"); --T;
    puts("200 0"); --T;

    for (int i = -11; i <= 4; ++i) {
        printf("1 %d\n", i);
        --T;
    }

    while (T--) test_case();

    return 0;
}
