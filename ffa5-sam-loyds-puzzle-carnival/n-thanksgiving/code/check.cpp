#include <cassert>
#include <cstdio>

#define MAXT 1000
#define MAXS 300

const int pts[] = { 0, 1, 2, 3, 5, 10, 20, 25, 50 };

int SA, SB, SC;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Testing case %d ..\n", t);
        scanf("%d%d%d", &SA, &SB, &SC);

        assert(0 <= SA && SA <= MAXS);
        assert(0 <= SB && SB <= MAXS);
        assert(0 <= SC && SC <= MAXS);

        int total = 0;
        int nshots = 0;
        for (int i = 0; i < 9; ++i) {
            int n;
            scanf("%d", &n);

            nshots += n;
            total  += pts[i] * n;
        }

        assert(total == SA + SB + SC);
        assert(nshots == 18);
    }

    puts("OK");

    return 0;
}
