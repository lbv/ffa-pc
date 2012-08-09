#include <cassert>
#include <cctype>
#include <cstring>
#include <cstdio>

#define MAXT 10
#define MAXLINE 10000
#define MAXWORD 250
#define MAXQ 300
#define MAXM 10
#define MAXPERLINE 30

#define MAXNUMWORDS 300

typedef unsigned int u32;

//
// I/O
//
#define BUF 65536
struct Reader {
    char buf[BUF]; char b; int bi, bz;
    Reader() { bi=bz=0; read(); }
    void read() {
        if (bi==bz) { bi=0; bz = fread(buf, 1, BUF, stdin); }
        b = bz ? buf[bi++] : 0; }
    void skip() { while (b > 0 && b <= 32) read(); }
    u32 next_u32() {
        u32 v = 0; for (skip(); b > 32; read()) v = v*10 + b-48; return v; }
    void skip_line() {
        for (; b != 10 && b != 13 && b != 0; read());
        char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
    void next_real_line(char *s, int &l) {
        for (l = 0; b != 10 && b != 13 && b != 0; read()) *s++ = b, ++l;
        *s = 0; char p = b; read();
        if ((p == 10 && b == 13) || (p == 13 && b == 10)) read(); }
    void next(char *s) { for (skip(); b > 32; read()) *s++ = b; *s = 0; }
    char next_char() { skip(); char c = b; read(); return c; }
};


int M, Q;
char line[MAXLINE + 1];
char word[MAXWORD + 1];
char suff[MAXWORD + 1];
int len;
char typ;


int main()
{
    Reader rr;
    int T = rr.next_u32();
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        M = rr.next_u32();
        rr.skip_line();
        assert(1 <= M && M <= MAXM);

        while (M--) {
            rr.next_real_line(line, len);
            assert(len <= MAXLINE);

            int nwords = 0;
            int i = 0;
            int j;
            while (true) {
                while(i < len && ! isalpha(line[i])) ++i;
                if (i >= len) break;

                for (j = 0; isalpha(line[i]); ++i, ++j)
                    word[j] = tolower(line[i]);
                word[j] = 0;

                assert(j <= MAXWORD);
                ++nwords;
            }

            assert(1 <= nwords && nwords <= MAXPERLINE);
        }

        Q = rr.next_u32();
        assert(1 <= Q && Q <= MAXQ);

        while (Q--) {
            rr.skip();
            typ = rr.next_char();
            rr.next(suff);

            assert(typ == 'F' || typ == 'L' || typ == 'N');

            len = strlen(suff);
            assert(1 <= len && len <= MAXWORD);
        }
    }

    puts("OK");

    return 0;
}
