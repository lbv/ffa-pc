#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 400
#define MAXL 50

const char sym[] = "@#$%&";
const int nsym = 5;

const int MAXK = (MAXL - 1) / 2;
char word[MAXL + 1];

char rand_letter()
{
    if (rand() % 10 == 0)
        return sym[rand() % nsym];
    return 'A' + (rand() % 26);
}

void test_case()
{
    int k = rand() % (MAXK + 1);

    for (int i = 0; i <= k; ++i)
        word[i] = rand_letter();

    for (int i = k, j = k; j >= 0; --j, ++i)
        word[i] = word[j];
    word[2*k + 1] = 0;

    printf("%s\n", word);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    puts("A"); --T;
    puts("ZZZ"); --T;
    puts("XYXYX"); --T;

    for (int i = 0; i < 2*MAXK + 1; ++i)
        putchar(sym[0]);
    putchar('\n'); --T;

    while (T--) test_case();

    return 0;
}
