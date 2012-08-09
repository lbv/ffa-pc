#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

#define MAXT   1250
#define MAXLEN 50
#define MAXN   100

const char vow[] = "aeiou";
const char con[] = "bcdfghjklmnpqrstvwxyz";

void test_case(bool crit = false)
{
    int N = rand() % MAXN + 1;
    if (crit) N = MAXN;

    printf("%d\n", N);

    while (N--) {
        int len = rand() % MAXLEN + 1;
        if (crit) len = MAXLEN;

        for (int i = 0; i < len; ++i)
            putchar('a' + (rand() % 26));
        putchar('\n');
    }
}

void test_case2()
{
    int N = min(MAXLEN + 1, MAXN);
    printf("%d\n", N);

    for (int v = 0; v <= MAXLEN && N > 0; ++v) {
        int c = MAXLEN - v;

        for (int i = 0; i < v; ++i)
            putchar(vow[rand() % 5]);
        for (int i = 0; i < c; ++i)
            putchar(con[rand() % 21]);
        putchar('\n');
        --N;
    }
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf(
"1\n"
"a\n"
"2\n"
"e\n"
"i\n"
"3\n"
"a\n"
"b\n"
"c\n"
    );
    T -= 3;

    test_case(true); --T;
    test_case2(); --T;
    while (T--) test_case();

    return 0;
}
