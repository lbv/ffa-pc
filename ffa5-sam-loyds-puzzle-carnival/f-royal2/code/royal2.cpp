#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
using namespace std;


#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)


int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }


struct Triple {
    int a, b, c;
    Triple(int A, int B, int C) : a(A), b(B), c(C) {
        if (c < b) swap(b, c);
        if (b < a) swap(a, b);
        if (c < b) swap(b, c);
    }
    bool operator<(const Triple &x) const {
        if (a != x.a) return a < x.a;
        if (b != x.b) return b < x.b;
        return c < x.c;
    }
};
typedef set<Triple>  TS;
typedef map<int, TS> ITSM;


int L;
ITSM triples;


void prepare()
{
    for (int n = 1; n <= 1000; ++n)
        for (int m = n + 1; m <= 1000; ++m) {
            if ((m - n) % 2 == 0) continue;

            int g = gcd(m, n);
            if (g != 1) continue;

            Triple t(m*m - n*n, 2*m*n, m*m + n*n);

            if (t.c >= 1000000) continue;

            triples[t.a].insert(t);
            triples[t.b].insert(t);
            triples[t.c].insert(t);
        }
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &L);

        const TS &ts = triples[L];
        printf("Case %d: %d\n", ++ncase, ts.size());

        cFor (TS, t, ts)
            printf("%d %d %d\n", t->a, t->b, t->c);
    }

    return 0;
}
