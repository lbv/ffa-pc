#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAXT 1000
#define MAXL 1000.0

#define EPS (1e-9)

double A, B, h, x;

void solve()
{
    double lo = 0.0;
    double hi = min(A, B);

    double L;  // total width of the corridor

    double a, b;  // distances A and B, from the floor, to the crossing point
    double p, q;  // vertical height of A and B
    double r, s;  // horizontal distances from the cross point to the walls
    double alpha;  // angle at which blade A is, relative to the floor
    double beta;   // angle of blade B

    double prev_r = -1.0;
    double prev_s = -1.0;

    while (true) {
        L = (lo + hi) / 2.0;

        alpha = acos(L / A);
        beta = acos(L / B);

        p = A * sin(alpha);
        q = B * sin(beta);

        a = h*A / p;
        b = h*B / q;

        r = a * cos(alpha);
        s = b * cos(beta);

        if (r + s > L) hi = L;
        else lo = L;

        if (fabs(r - prev_r) < EPS && fabs(s - prev_s) < EPS) break;
        prev_r = r;
        prev_s = s;
    }

    x = max(r, s);
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%lf%lf%lf", &A, &B, &h);
        assert(0 < A && A < MAXL);
        assert(0 < B && B < MAXL);
        assert(0 < h && h < MAXL);

        solve();
        printf("Case %d: %.3lf\n", ++ncase, x);
    }

    return 0;
}
