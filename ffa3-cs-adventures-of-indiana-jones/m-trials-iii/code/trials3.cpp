#include <cassert>
#include <cstdio>
#include <cstring>

#define MAXT 10000

#define MAXCONST 999
#define MAXN     1000000000000000LL
#define MOD 1000

#define Zero(v) memset(v, 0, sizeof(v))

typedef long long i64;

// Matrix Exponentiation
typedef int t_m;
#define MAXR 2
#define MAXC 2
struct Matrix {
    int r, c;
    t_m m[MAXR][MAXC];
    void init(int R, int C) { Zero(m); r=R; c=C; }
};

void matrix_mul(const Matrix &a, const Matrix &b, Matrix &c)
{
    c.r = a.r, c.c = b.c;
    t_m x;
    for (int i = 0; i < c.r; ++i)
        for (int j = 0; j < c.c; ++j) {
            x = 0;
            for (int k = 0; k < a.c; ++k)
                x += a.m[i][k] * b.m[k][j];
            c.m[i][j] = x % MOD;
        }
}

void matrix_exp(const Matrix &m, i64 e, Matrix &r)
{
    if (e == 1) { r = m; return; }

    Matrix x;
    if (e % 2 == 0) {
        matrix_exp(m, e / 2, x);
        matrix_mul(x, x, r);
        return;
    }

    matrix_exp(m, e-1, x);
    matrix_mul(x, m, r);
}

int a, b, x, y;
int ans;
i64 n;

void solve()
{
    if (n == 1) { ans = a; return; }
    if (n == 2) { ans = b; return; }

    Matrix mat;
    mat.init(2, 2);
    mat.m[0][0] = x;
    mat.m[0][1] = y;
    mat.m[1][0] = 1;
    mat.m[1][1] = 0;

    Matrix R;
    matrix_exp(mat, n - 2, R);

    ans = R.m[0][0] * b + R.m[0][1] * a;
    ans %= MOD;
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d%d%lld", &a, &b, &x, &y, &n);
        assert(0 <= a && a <= MAXCONST);
        assert(0 <= b && b <= MAXCONST);
        assert(0 <= x && x <= MAXCONST);
        assert(0 <= y && y <= MAXCONST);
        assert(1 <= n && n <= MAXN);

        solve();

        printf("Case %d: %03d\n", ++ncase, ans);
    }

    return 0;
}
