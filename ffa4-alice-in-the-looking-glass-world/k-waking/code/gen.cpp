#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 100
#define MAXLEN 300

void test_case(bool crit = false)
{
    int a = rand() % MAXLEN + 1;
    int b = rand() % MAXLEN + 1;

    if (crit) a = b = MAXLEN;

    puts("");
    for (int i = 0; i < a; ++i)
        putchar('A' + (rand() % 26));
    putchar('\n');

    for (int i = 0; i < b; ++i)
        putchar('A' + (rand() % 26));
    putchar('\n');
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf(
"\n"
"A\n"
"A\n"
"\n"
"X\n"
"Y\n"
"\n"
"ABCDE\n"
"ABCDE\n"
"\n"
"ABCDEFGHIJKLMNOPQRSTUVWXYZ\n"
"ZYXWVUTSRQPONMLKJIHGFEDCBA\n"
    );
    T -= 4;

    test_case(true);
    while (T--) test_case();

    return 0;
}
