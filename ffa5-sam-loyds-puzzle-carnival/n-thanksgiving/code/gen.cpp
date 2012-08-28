#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 1000

const int pts[] = { 0, 1, 2, 3, 5, 10, 20, 25, 50 };

void test_case()
{
    int S[3]   = { 0 };
    int cnt[9] = { 0 };

    for (int p = 0; p < 3; ++p)
        for (int i = 0; i < 6; ++i) {
            int shot = rand() % 9;
            S[p] += pts[shot];
            ++cnt[shot];
        }

    printf("%d %d %d\n", S[0], S[1], S[2]);

    for (int i = 0; i < 9; ++i)
        printf("%s%d", i == 0 ? "" : " ", cnt[i]);
    putchar('\n');
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("0 0 0");
    puts("18 0 0 0 0 0 0 0 0"); --T;

    puts("300 300 300");
    puts("0 0 0 0 0 0 0 0 18"); --T;

    puts("300 60 6");
    puts("0 6 0 0 0 6 0 0 6"); --T;

    while (T--) test_case();

    return 0;
}
