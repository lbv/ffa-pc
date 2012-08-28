#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXT 10000
#define MAXLEN 11

char str[MAXLEN + 1];
int len;

bool valid()
{
    int n = 0;
    for (int i = 0; i < len; ++i)
        if (! isdigit(str[i])) {
            assert(str[i] == '_');
            ++n;
        }

    return n == 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);

        scanf("%s", str);
        len = strlen(str);

        assert(1 <= len && len <= MAXLEN);
        assert(valid());
    }

    puts("OK");

    return 0;
}
