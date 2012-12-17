#include <cstdio>

int r, L, D;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d", &r, &L, &D);
        printf("Case %d: ", ++ncase);
        if ((r-1) * D >= L*r)
            puts("yes");
        else
            puts("no");
    }

    return 0;
}
