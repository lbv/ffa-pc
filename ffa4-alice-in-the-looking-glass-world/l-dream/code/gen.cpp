#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define MAXT 10
#define MAXLINE 10000
#define MAXWORD 250
#define MAXQ 300
#define MAXM 10
#define MAXPERLINE 30

#define MAXNUMWORDS 300

#define Zero(v) memset((v), 0, sizeof(v))

char dict[MAXNUMWORDS][MAXWORD + 1];
char suff[MAXWORD + 1];

const char ws[] = " -=?.,:;%$";
const int nws = 10;

const char types[] = "FLN";

void test_case(bool crit = false)
{
    int M = rand() % MAXM + 1;
    if (crit) M = MAXM;

    printf("\n%d\n", M);

    int N = 0;
    while (M--) {
        int W = rand() % MAXPERLINE + 1;
        if (crit) W = MAXPERLINE;

        while (W--) {
            int len = rand() % MAXWORD + 1;
            if (crit) len = MAXWORD;

            for (int i = 0; i < len; ++i) {
                dict[N][i] = rand() % 2 == 0 ? 'a' : 'A';
                dict[N][i] += rand() % 26;
            }
            dict[N][len] = 0;

            printf("%s%c", dict[N], ws[rand() % nws]);
            ++N;
        }
        putchar('\n');
    }

    int Q = rand() % MAXQ + 1;
    if (crit) Q = MAXQ;

    printf("%d\n", Q);

    while (Q--) {
        char typ = types[rand() % 3];

        int n = rand() % N;
        int len = strlen(dict[n]);

        int ls = rand() % len + 1;

        strcpy(suff, dict[n] + len - ls);

        if (rand() % 10 == 0) {
            ls = rand() % MAXWORD + 1;
            for (int i = 0; i < ls; ++i)
                suff[i] = 'a' + (rand() % 26);
            suff[ls] = 0;
        }

        for (int i = 0; i < ls; ++i)
            suff[i] = tolower(suff[i]);

        printf("%c %s\n", typ, suff);
    }
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf(
"\n"
"2\n"
"firstVwXyZ-wXyZ  UVWXYZ\n"
"lastwxyz\n"
"8\n"
"F wxyz\n"
"L wxyz\n"
"F vwxyz\n"
"L vwxyz\n"
"F uvwxyz\n"
"L uvwxyz\n"
"N z\n"
"F ab\n"
);
    --T;

    test_case(true); --T;
    while (T--) test_case();

    return 0;
}
