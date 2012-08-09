#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 200
#define MAXR 16
#define MAXC 16

char grid[MAXR][MAXC + 1];

void test_case(bool crit = false)
{
    int R, C;

    do {
        R = rand() % MAXR + 1;
        C = rand() % MAXC + 1;
    } while (R * C < 2);

    if (crit) R = C = 16;

    printf("\n%d %d\n", R, C);

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (rand() % 3 == 0)
                grid[i][j] = '#';
            else
                grid[i][j] = '.';
        }
        grid[i][C] = 0;
    }

    int r, c;
    r = rand() % R;
    c = rand() % C;

    grid[r][c] = 'A';

    do {
        r = rand() % R;
        c = rand() % C;
    } while (grid[r][c] == 'A');
    grid[r][c] = 'Q';

    for (int i = 0; i < R; ++i)
        puts(grid[i]);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf(
"\n"
"1 2\n"
"QA\n"
"\n"
"1 9\n"
"..A...Q..\n"
"\n"
"1 10\n"
"..A....Q..\n"
"\n"
"8 10\n"
"..#......#\n"
".##..###.#\n"
"....#....#\n"
".####..###\n"
"...A#Q....\n"
".####...#.\n"
"....#...#.\n"
"....#...#.\n"
);
    T -= 4;

    test_case(true); --T;

    while (T--) test_case();

    return 0;
}
