#include <cctype>
#include <cstdio>


#define MAXLEN 80


int N;
int ncomments, nchars;
char c;

char line[MAXLEN + 2];
char *p;


void next_char()
{
    while (*p == 0) {
        if (N == 0) { c = 0; return; }
        fgets(line, MAXLEN + 2, stdin);
        p = line;
        --N;
    }
    c = *p++;
}

void parse_string()
{
    next_char();
    while (true) {
        while (c != '"' && c != '\\') next_char();
        if (c == '"') return;
        next_char();
        if (c == '"') next_char();
    }
}

void parse_comment()
{
    next_char(); next_char();
    nchars += 2;

    while (true) {
        while (c != '*') { next_char(); ++nchars; }
        next_char();
        if (c == '/') {
            nchars += 2;
            ++ncomments;
            return;
        }
        ++nchars;
    }
}

void parse_literal()
{
    while (isdigit(c) || isupper(c) || islower(c)) next_char();
}

void parse()
{
    ncomments = nchars = 0;
    p = line;
    line[0] = 0;

    for (next_char(); c > 0; next_char()) {
        while (c == ' ' || c == '\n') next_char();

        if (c == '/') parse_comment();
        else if (c == '"') parse_string();
        else parse_literal();
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N); gets(line);
        parse();
        printf("Case %d: %d %d\n", ++ncase, ncomments, nchars);
    }

    return 0;
}
