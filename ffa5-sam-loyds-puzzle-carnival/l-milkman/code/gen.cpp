#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXT 1000
#define MAXC 50
#define MAXM 20

void test_case(bool crit = false)
{
    int C = rand() % (MAXC - 1) + 2;

    int M1 = rand() % min(MAXM, C) + 1;

    int M2 = rand() % min(MAXM, C) + 1;

    if (rand() % 20 == 0) {
        C = rand() % MAXC + 1;
        M1 = rand() % MAXM + 1;
        M2 = rand() % MAXM + 1;
    }

    if (crit) C = MAXC, M1 = M2 = MAXM;

    int Q1 = rand() % M1 + 1;
    int Q2 = rand() % M2 + 1;

    printf("%d %d %d %d %d\n", C, M1, Q1, M2, Q2);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("1 1 1 1 1"); --T;
    puts("2 1 1 1 1"); --T;
    puts("1 2 2 2 1"); --T;
    puts("50 20 20 20 20"); --T;

    test_case(true); --T;
    test_case(true); --T;
    while (T--) test_case();

    return 0;
}
