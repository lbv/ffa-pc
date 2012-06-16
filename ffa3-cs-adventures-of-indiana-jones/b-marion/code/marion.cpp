#include <cassert>
#include <cstdio>

#define MAXT 1000
#define MAXN 100
#define MAXI 1500

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        int N;
        scanf("%d", &N);
        assert(1 <= N && N <= MAXN);

        int grundy = 0;
        for (int i = 1; i <= N; ++i) {
            int x;
            scanf("%d", &x);
            assert(1 <= x && x <= MAXI);
            grundy ^= (x % (i + 1));
        }

        printf("Case %d: Marion %s\n", ++ncase, grundy ? "wins" : "loses");
    }

    return 0;
}
