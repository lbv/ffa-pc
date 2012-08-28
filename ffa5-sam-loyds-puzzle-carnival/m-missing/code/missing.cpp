#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXLEN 11

char str[MAXLEN + 1];
int len;

int solve()
{
    int n = 0;
    for (int i = 0; i < len; ++i)
        if (isdigit(str[i]))
            n += str[i] - '0';

    while (n > 9) {
        int x = 0;
        while (n > 0) {
            x += n % 10;
            n /= 10;
        }
        n = x;
    }

    return n == 9 ? 9 : 9 - n;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%s", str);
        len = strlen(str);

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
