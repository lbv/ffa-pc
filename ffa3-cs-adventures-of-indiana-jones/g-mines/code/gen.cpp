#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 100
#define MAXR 100
#define MAXC 100
#define MAXH 6

void case1()
{
    printf(
"5 3 1\n"
"###\n"
"#S#\n"
"#I#\n"
"#@#\n"
"###\n"
);
}

void case2()
{
    printf(
"1 2 0\n"
"SI\n"
);
}

void case3()
{
    printf(
"1 3 0\n"
"S#I\n"
);
}

void case4()
{
    printf(
"7 12 4\n"
"############\n"
"#.@..S...@.#\n"
"#..........#\n"
"#....I.....#\n"
"#..........#\n"
"#@........@#\n"
"############\n"
);
}

void case5()
{
    printf(
"5 8 1\n"
"########\n"
"#@#..S.#\n"
"###....#\n"
"#....I.#\n"
"########\n"
);
}

char map[MAXR][MAXC + 1];

void test_case()
{
    int H = rand() % (MAXH + 1);
    int R, C;

    if (rand() % 10 == 0)
        R = MAXR, C = MAXC;
    else
        do {
            R = rand() % MAXR + 1;
            C = rand() % MAXC + 1;
        } while (R * C < H + 2);

    printf("%d %d %d\n", R, C, H);

    for (int i = 0; i < R; ++i) {
        map[i][C] = 0;
        for (int j = 0; j < C; ++j) {
            map[i][j] = '.';

            if (rand() % 4 == 0) map[i][j] = '#';
        }
    }

    int r, c;
    do {
        r = rand() % R;
        c = rand() % C;
    } while (map[r][c] != '.' && map[r][c] != '#');
    map[r][c] = 'S';
    do {
        r = rand() % R;
        c = rand() % C;
    } while (map[r][c] != '.' && map[r][c] != '#');
    map[r][c] = 'I';

    for (int i = 0; i < H; ++i) {
        do {
            r = rand() % R;
            c = rand() % C;
        } while (map[r][c] != '.' && map[r][c] != '#');
        map[r][c] = '@';
    }

    for (int i = 0; i < R; ++i)
        printf("%s\n", map[i]);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    case1(); --T;
    case2(); --T;
    case3(); --T;
    case4(); --T;
    case5(); --T;

    while(T--) test_case();

    return 0;
}
