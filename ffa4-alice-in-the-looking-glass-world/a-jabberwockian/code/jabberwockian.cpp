#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXT   25000
#define MAXLEN 50

char word[MAXLEN + 1];
char norm[MAXLEN + 1];  // normalised string -- only composed of 'C' and 'V'
int len;

bool rule1(int i)
{
    if (i + 2 >= len) return false;
    if (strncmp("VCV", norm + i, 3) != 0) return false;
    if (i + 3 == len && word[i + 2] == 'e') return false;
    return true;
}

bool rule2a(int i)
{
    if (i - 1 < 0 || i + 2 >= len) return false;
    if (strncmp("VCCV", norm + i - 1, 4) != 0) return false;
    if (i + 3 == len && word[i + 2] == 'e') return false;
    return true;
}

bool rule2b(int i)
{
    if (i - 1 < 0 || i + 3 >= len) return false;
    if (strncmp("VCCCV", norm + i - 1, 5) != 0) return false;
    if (i + 4 == len && word[i + 3] == 'e') return false;
    return true;
}

void process()
{
    for (int i = 0; i < len; ++i) {
        assert(islower(word[i]));
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
            word[i] == 'o' || word[i] == 'u')
            norm[i] = 'V';
        else
            norm[i] = 'C';
    }

    for (int i = 0; i < len; ++i) {
        putchar(word[i]);

        if (rule1(i) || rule2a(i) || rule2b(i))
            putchar('-');
    }
    putchar('\n');
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%s", word);
        len = strlen(word);
        assert(1 <= len && len <= MAXLEN);

        printf("Case %d: ", ++ncase);

        process();
    }

    return 0;
}
