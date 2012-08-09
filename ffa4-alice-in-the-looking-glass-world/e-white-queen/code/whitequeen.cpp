#include <cstdio>


#define MAXN 1000000
#define MOD  1000000007


typedef long long i64;


i64 fact[MAXN + 1];
int n, k;


void ext_euclid(int a, int b, int &x, int &y, int &gcd) {
    x = 0; y = 1; gcd = b;
    int m, n, q, r;
    for (int u=1, v=0; a != 0; gcd=a, a=r) {
        q = gcd / a; r = gcd % a;
        m = x-u*q; n = y-v*q;
        x=u; y=v; u=m; v=n;
    }
}
int mod_inv(int n, int m) {
    int x, y, gcd;
    ext_euclid(n, m, x, y, gcd);
    if (gcd == 1) return x % m;
    return 0;
}
int mod_pow(int _b, i64 e, int m) {
    i64 res = 1;
    for (i64 b=_b; e; e >>= 1, b = b*b%m) if (e & 1) res = res*b%m;
    return res;
}



int solve()
{
    int q = n / k;
    int r = n % k;

    i64 num, den;

    if (n < k) num = den = 1;
    else {
        num = fact[n];
        den = mod_pow(fact[q], k, MOD);
        den = den * mod_pow(q + 1, r, MOD) % MOD;
    }

    num = num * fact[k] % MOD;
    den = den * fact[r] % MOD;
    den = den * fact[k-r] % MOD;

    int inv = mod_inv(den, MOD);
    if (inv < 0) inv += MOD;

    return num * inv % MOD;
}

void prepare()
{
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i)
        fact[i] = fact[i - 1] * i % MOD;
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &n, &k);
        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
