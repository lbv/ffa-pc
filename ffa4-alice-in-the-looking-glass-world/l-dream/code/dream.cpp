#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


#define MAXLINE 10000
#define MAXWORD 250

#define Zero(v) memset((v), 0, sizeof(v))


typedef unsigned int u32;


void reverse(char *s)
{
    int len = strlen(s);
    for (int i = 0, j = len - 1; i < j; ++i, --j)
        swap(s[i], s[j]);
}

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

//
// Trie
//
struct Trie {
    struct Node {
        int ch[26];
        int n;
        int first, last;
        Node() { n=0; Zero(ch); first = last = -1; }
    };
    int sz;
    vector<Node> nodes;
    void init() { nodes.clear(); nodes.resize(1); sz = 1; }
    void insert(const char *s) {
        int idx, cur = 0;

        for (; *s; ++s) {
            idx = *s - 'a';
            if (! nodes[cur].ch[idx]) {
                nodes[cur].ch[idx] = sz++;
                nodes.resize(sz);
            }

            ++nodes[cur].n;
            if (nodes[cur].first == -1)
                nodes[cur].first = idx;
            nodes[cur].last = idx;

            cur = nodes[cur].ch[idx];
        }

        ++nodes[cur].n;
        if (nodes[cur].first == -1)
            nodes[cur].first = -3;
        nodes[cur].last = -3;
    }

    void first(const char *s, char *r) {
        int idx, cur = 0;

        int j = 0;
        for (; *s; ++s) {
            idx = *s - 'a';
            if (! nodes[cur].ch[idx]) {
                strcpy(r, "*");
                return;
            }
            r[j++] = *s;
            cur = nodes[cur].ch[idx];
        }

        while (nodes[cur].first != -3) {
            idx = nodes[cur].first;
            r[j++] = 'a' + idx;
            cur = nodes[cur].ch[idx];
        }
        r[j] = 0;
    }

    void last(const char *s, char *r) {
        int idx, cur = 0;

        int j = 0;
        for (; *s; ++s) {
            idx = *s - 'a';
            if (! nodes[cur].ch[idx]) {
                strcpy(r, "*");
                return;
            }
            r[j++] = *s;
            cur = nodes[cur].ch[idx];
        }

        while (nodes[cur].last != -3) {
            idx = nodes[cur].last;
            r[j++] = 'a' + idx;
            cur = nodes[cur].ch[idx];
        }
        r[j] = 0;
    }

    int number(const char *s) {
        int idx, cur = 0;

        for (; *s; ++s) {
            idx = *s - 'a';
            if (! nodes[cur].ch[idx]) return 0;
            cur = nodes[cur].ch[idx];
        }

        return nodes[cur].n;
    }
};


int M, Q;
char line[MAXLINE + 1];
char word[MAXWORD + 1];
char suff[MAXWORD + 1];
int len;
char typ;

Trie trie;

int main()
{
    Reader rr;
    int T = rr.next_u32();

    int ncase = 0;
    while (T--) {
        M = rr.next_u32();
        rr.skip_line();

        trie.init();
        while (M--) {
            rr.next_real_line(line, len);

            int i = 0;
            int j;
            while (true) {
                while(i < len && ! isalpha(line[i])) ++i;
                if (i >= len) break;

                for (j = 0; isalpha(line[i]); ++i, ++j)
                    word[j] = tolower(line[i]);
                word[j] = 0;

                reverse(word);
                trie.insert(word);
            }
        }

        Q = rr.next_u32();
        rr.skip_line();

        printf("Case %d:\n", ++ncase);

        while (Q--) {
            rr.skip();
            typ = rr.next_char();
            rr.next(suff);
            reverse(suff);

            switch (typ) {
            case 'F':
                trie.first(suff, word);
                reverse(word);
                printf("%s\n", word);
                break;

            case 'L':
                trie.last(suff, word);
                reverse(word);
                printf("%s\n", word);
                break;

            case 'N':
                int n = trie.number(suff);
                printf("%d\n", n);
            }
        }

    }

    return 0;
}
