#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 5000
#define MAXA 1000
#define MAXB 1000

void test_case()
{
    int A = rand() % (MAXA - 2) + 3;
    int B = rand() % MAXB + 1;

    int s1, s2;
    do {
        s1 = rand() % (A - 1) + 1;
        s2 = rand() % (A - 1) + 1;
    } while (s1 == s2);

    printf("%d %d %d %d\n", A, B, s1, s2);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("3 1 1 2\n"); --T;
    printf("3 1 2 1\n"); --T;
    printf("1000 1000 999 998\n"); --T;
    printf("1000 1000 1 2\n"); --T;

    while (T--) test_case();

    return 0;
}
