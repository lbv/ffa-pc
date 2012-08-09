#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT   25000
#define MAXLEN 50

void test_case()
{
    int len = rand() % MAXLEN + 1;

    while (len--) {
        int idx = rand() % 26;
        char c = 'a' + idx;
        putchar(c);
    }
    putchar('\n');
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("jabberwock"); --T;
    puts("bandersnatch"); --T;
    puts("galumph"); --T;
    puts("frumious"); --T;
    puts("wabe"); --T;
    puts("a"); --T;
    puts("aaa"); --T;
    puts("aba"); --T;
    puts("abe"); --T;
    puts("abeb"); --T;
    puts("uzzzu"); --T;
    puts("uzzzzu"); --T;
    puts("axexixoxuxaxaxaxaxaxaxaxaxaxe"); --T;
    puts("abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwx"); --T;

    while (T--) test_case();

    return 0;
}
