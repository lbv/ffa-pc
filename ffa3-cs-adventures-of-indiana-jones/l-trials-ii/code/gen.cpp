#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define MAXT 500
#define MAXR 80
#define MAXC 80
#define MAXLEN 50

#define Zero(v) memset(v, 0, sizeof(v))

char word[MAXLEN + 1];
char map[MAXR][MAXC + 1];
bool valid[26];
char good[26];
int ngood;

void test_case(bool special)
{
    int R = rand() % MAXR + 1;
    int C = rand() % MAXC + 1;

    if (special) R = MAXR, C = MAXC;

    printf("%d %d\n", R, C);

    int len = rand() % MAXLEN + 1;
    if (special) len = MAXLEN;

    Zero(valid);
    ngood = 0;
    for (int i = 0; i < len; ++i) {
        int n = rand() % 26;
        word[i] = 'A' + n;

        if (! valid[n]) {
            valid[n] = true;
            good[ngood++] = 'A' + n;
        }
    }
    word[len] = 0;

    printf("%s\n", word);


    bool flg = rand() % 2;

    for (int i = 0; i < R; ++i) {
        map[i][C] = 0;

        bool flg2 = flg;
        flg = !flg;

        for (int j = 0; j < C; ++j, flg2 = ! flg2) {
            if (flg2) { map[i][j] = '|'; continue; }

            map[i][j] = good[rand() % ngood];
            if (special) continue;

            if (rand() % 3 == 0)
                map[i][j] = rand() % 26 + 'A';
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

    printf("1 1\nA\n|\n"); --T;
    printf("1 1\nA\nA\n"); --T;
    printf("1 1\nA\nB\n"); --T;

    test_case(true); --T;
    while (T--) test_case(false);

    return 0;
}
