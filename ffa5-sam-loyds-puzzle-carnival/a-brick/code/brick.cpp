#include <cstdio>

int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }

int a, b, c, d;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d/%d %d/%d", &a, &b, &c, &d);

        int p = b*c;
        int q = (b-a)*d;
        int g = gcd(p, q);

        p /= g;
        q /= g;

        printf("Case %d: ", ++ncase);

        if (q == 1)
            printf("%d\n", p);
        else
            printf("%d/%d\n", p, q);
    }

    return 0;
}
