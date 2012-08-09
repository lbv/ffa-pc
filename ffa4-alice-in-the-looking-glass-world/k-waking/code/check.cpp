#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXT 100
#define MAXLEN 300

char str[MAXLEN + 1];
int len;

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
        for (int i = 0; i < len; ++i)
            assert(isupper(str[i]));

        scanf("%s", str);
        len = strlen(str);

        assert(1 <= len && len <= MAXLEN);
        for (int i = 0; i < len; ++i)
            assert(isupper(str[i]));
    }

    puts("OK");

    return 0;
}
