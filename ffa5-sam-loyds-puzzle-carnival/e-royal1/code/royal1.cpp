#include <cstdio>

typedef unsigned long long u64;

int N;

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);

        u64 p = N;
        p *= N + 1;
        p /= 2;
        ++p;

        printf("Case %d: %llu\n", ++ncase, p);
    }

    return 0;
}
