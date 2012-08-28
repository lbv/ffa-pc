#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 10000
#define MAXP 1000000000


int dig[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };


int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }

void test_case()
{
    int p, q;

    if (rand() % 5 != 0) {
        random_shuffle(dig, dig + 9);

        do {
            int k = rand() % 8 + 1;
            p = 0;
            for (int i = 0; i < k; ++i) { p *= 10; p += dig[i]; }
            q = 0;
            for (int i = k; i < 9; ++i) { q *= 10; q += dig[i]; }
        } while (p >= q);

        int g = gcd(p, q);
        p /= g;
        q /= g;

        int m = max(p, q);
        int f = rand() % (MAXP / m) + 1;

        p *= f;
        q *= f;
    }
    else {
        if (rand() % 2 == 0) {
            q = rand() % (MAXP - 1) + 2;
            p = rand() % (q - 1) + 1;
        }
        else {
            q = rand() % 1000 + 2;
            p = rand() % (q - 1) + 1;
        }
    }

    printf("%d/%d\n", p, q);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    for (int i = 2; i <= 30; ++i) {
        printf("%d/%d\n", 1, i);
        --T;
    }

    puts("500000000/1000000000"); --T;

    while (T--) test_case();

    return 0;
}
