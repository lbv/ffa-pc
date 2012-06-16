#include <cassert>
#include <cstdio>
#include <cstdlib>

#define MAXT 5000
#define MAXA 1000
#define MAXB 1000

int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }

int A, B, S1, S2;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d%d", &A, &B, &S1, &S2);
        assert(1 <= A && A <= MAXA);
        assert(1 <= B && B <= MAXB);
        assert(1 <= S1 && S1 < A);
        assert(1 <= S2 && S2 < A);
        assert(S1 != S2);

        int p = abs(A*B * (S1-S2));
        int q = abs(A*A - A*(S1+S2) + S1*S2);
        int g = gcd(p, q);
        p /= g;
        q /= g;

        printf("Case %d: %d/%d\n", ++ncase, p, q);
    }

    return 0;
}
