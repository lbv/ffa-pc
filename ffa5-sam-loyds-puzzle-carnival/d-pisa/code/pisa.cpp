#include <cstdio>

int H, D;

int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &H, &D);

        int num = H * (D + 1);
        int den = D - 1;

        int feet = num / den;

        num %= den;
        num *= 12;

        printf("Case %d: %d ft ", ++ncase, feet);

        if (num % den == 0)
            printf("%d in\n", num / den);
        else {
            int inches = num / den;
            if (inches > 0)
                printf("%d ", inches);

            num %= den;

            int g = gcd(num, den);

            num /= g;
            den /= g;

            printf("%d/%d in\n", num, den);
        }
    }

    return 0;
}
