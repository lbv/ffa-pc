#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXT   1250
#define MAXLEN 50
#define MAXN   100

char str[MAXLEN + 1];
int N;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);

        scanf("%d", &N);
        assert(0 < N && N <= MAXN);

        while (N--) {
            scanf("%s", str);
            int len = strlen(str);
            assert(1 <= len && len <= MAXLEN);

            for (int i = 0; i < len; ++i)
                assert(islower(str[i]));
        }
    }

    puts("OK");

    return 0;
}
