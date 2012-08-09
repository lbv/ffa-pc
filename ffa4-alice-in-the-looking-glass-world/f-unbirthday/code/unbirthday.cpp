#include <cstdio>


#define MAXP 10000000


typedef unsigned int u32;


void euler_phi(u32 a[], u32 N) {
    for (u32 i = 1; i <= N; i++) a[i] = i;
    for (u32 i = 2; i <= N; i += 2) a[i] = i/2;
    for (u32 i = 3; i <= N; i += 2)
        if (a[i] == i) {
            a[i]--; for (u32 j = i+i; j <= N; j += i) a[j] -= a[j]/i;
        }
}


int P;
u32 phi[MAXP + 1];


void prepare()
{
    euler_phi(phi, MAXP);
    for (int i = 1; i <= MAXP; ++i)
        phi[i] += phi[i - 1];
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &P);

        printf("Case %d: %u\n", ++ncase, phi[P]);
    }

    return 0;
}
