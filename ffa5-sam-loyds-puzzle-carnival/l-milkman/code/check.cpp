#include <cassert>
#include <cstdio>

#define MAXT 1000
#define MAXC 50
#define MAXM 20

int C, M1, Q1, M2, Q2;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d%d%d%d", &C, &M1, &Q1, &M2, &Q2);

        assert(1 <= C && C <= MAXC);
        assert(1 <= Q1 && Q1 <= M1 && M1 <= MAXM);
        assert(1 <= Q2 && Q2 <= M2 && M2 <= MAXM);
    }

    puts("OK");

    return 0;
}
