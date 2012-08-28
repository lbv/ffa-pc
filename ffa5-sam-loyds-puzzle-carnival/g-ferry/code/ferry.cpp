#include <cstdio>

typedef long long i64;

i64 A, B;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%lld%lld", &A, &B);
        printf("Case %d: %lld\n", ++ncase, 3*A - B);
    }

    return 0;
}
