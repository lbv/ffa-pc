#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 500
#define MAXR 100
#define MAXC 100

char map[MAXR][MAXC + 1];

void case1()
{
    printf(
"6 6\n"
"@....@\n"
".@..@.\n"
"..@@..\n"
"..@@..\n"
".@..@.\n"
"@....@\n"
);
}

void case2()
{
    printf(
"6 6\n"
"@@@...\n"
"@@@...\n"
"@@@...\n"
"...@@@\n"
"...@@@\n"
"...@@@\n"
);
}

void test_case()
{
    int R = rand() % MAXR + 1;
    int C = rand() % MAXC + 1;

    if (rand() % 10 == 0) R = MAXR, C = MAXC;

    printf("%d %d\n", R, C);

    for (int i = 0; i < R; ++i) {
        map[i][C] = 0;
        for (int j = 0; j < C; ++j) {
            map[i][j] = '.';

            if (rand() % 3 == 0)
                map[i][j] = '@';

            if (rand() % 5 == 0)
                map[i][j] = '#';
        }
    }
    for (int i = 0; i < R; ++i)
        printf("%s\n", map[i]);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("1 1\n.\n"); --T;
    printf("1 1\n#\n"); --T;
    printf("1 1\n@\n"); --T;
    case1(); --T;
    case2(); --T;

    while (T--) test_case();

    return 0;
}
