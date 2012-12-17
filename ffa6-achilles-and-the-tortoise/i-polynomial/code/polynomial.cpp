#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;


#define MAXS 15


typedef long long i64;


char S[MAXS + 1];
int len;
int M, P;
i64 cs[4];
i64 es[4];
char sol[5];


i64 mod_pow(i64 _b, i64 e, int m) {
    i64 res = 1;
    for (i64 b=_b; e; e >>= 1, b = b*b%m) if (e & 1) res = res*b%m;
    return res;
}

bool check(int a, int b, int c, int d)
{
    int vs[4];
    vs[0] = S[a] - 'A' + 1;
    vs[1] = S[b] - 'A' + 1;
    vs[2] = S[c] - 'A' + 1;
    vs[3] = S[d] - 'A' + 1;

    for (int i = 0; i < 4; ++i)
        for (int j = i + 1; j < 4; ++j)
            if (vs[i] == vs[j]) return false;

    i64 t1 = cs[0] * mod_pow(vs[0], es[0], M) % M;
    i64 t2 = cs[1] * mod_pow(vs[1], es[1], M) % M;
    i64 t3 = cs[2] * mod_pow(vs[2], es[2], M) % M;
    i64 t4 = cs[3] * mod_pow(vs[3], es[3], M) % M;

    i64 poly = (t1 + t2 + t3 + t4) % M;
    return poly == P;
}

void solve()
{
    sol[0] = 0;

    len = strlen(S);
    sort(S, S + len);

    for (int a = len - 1; a >= 0; --a)
        for (int b = len - 1; b >= 0; --b)
            for (int c = len - 1; c >= 0; --c)
                for (int d = len - 1; d >= 0; --d)
                    if (check(a, b, c, d)) {
                        sol[0] = S[a];
                        sol[1] = S[b];
                        sol[2] = S[c];
                        sol[3] = S[d];
                        return;
                    }
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%s%d%d", S, &M, &P);
        for (int i = 0; i < 4; ++i) scanf("%lld", &cs[i]);
        for (int i = 0; i < 4; ++i) scanf("%lld", &es[i]);
        solve();
        printf("Case %d: %s\n", ++ncase, sol);
    }

    return 0;
}
