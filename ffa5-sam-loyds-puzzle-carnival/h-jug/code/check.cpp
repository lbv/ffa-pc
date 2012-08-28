#include <cassert>
#include <cstdio>
#include <cstring>

#define MAXT 400
#define MAXL 50

char word[MAXL + 1];
int len;

const char sym[] = "@#$%&";

bool is_palindrome()
{
    for (int i = 0, j = len - 1; i <= j; ++i, --j)
        if (word[i] != word[j])
            return false;
    return true;
}

bool is_valid(char c)
{
    if (c >= 'A' && c <= 'Z') return true;

    return strchr(sym, c) != NULL;
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);

        scanf("%s", word);
        len = strlen(word);

        assert(1 <= len && len < MAXL);
        assert(len % 2 != 0);
        assert(is_palindrome());

        for (int i = 0; i < len; ++i)
            assert(is_valid(word[i]));
    }

    puts("OK");

    return 0;
}
