#include <cassert>
#include <cstdio>

#define MAXT  5000
#define MAXR  10.0
#define MAXTM 30.0


double r, tm;


int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%lf%lf", &r, &tm);
        assert(1 < r && r <= MAXR);
        assert(0 < tm && tm <= MAXTM);
    }

    puts("OK");

    return 0;
}
