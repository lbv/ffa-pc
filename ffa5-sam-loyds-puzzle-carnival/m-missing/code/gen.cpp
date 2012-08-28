#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define MAXT 10000

typedef long long i64;


int dig[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
char str[12];

void test_case()
{
    random_shuffle(dig, dig + 10);

    int k = rand() % 9 + 1;

    i64 a = 0;
    for (int i = 0; i < k; ++i) { a *= 10; a += dig[i]; }
    i64 b = 0;
    for (int i = k; i < 10; ++i) { b *= 10; b += dig[i]; }

    sprintf(str, "%lld", a + b);

    int len = strlen(str);

    int idx;
    do {
        idx = rand() % len;
    } while (str[idx] == '0');

    // char d = str[idx];
    str[idx] = '_';

    //printf("%s %c %lld %lld\n", str, d, a, b);
    printf("%s\n", str);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    while (T--) test_case();

    return 0;
}
