#include <cstdio>

#define MAXN 1000000
#define MOD  1000003

typedef long long i64;

int n;
i64 puzzle[MAXN + 1];

void prepare()
{
    puzzle[1] = 3;
    for (int i = 2; i <= MAXN; ++i) {
        puzzle[i] = puzzle[i - 1] * 4 + (i % 2 == 0 ? 1 : -1);
        puzzle[i] %= MOD;
    }
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &n);
        printf("Case %d: %lld\n", ++ncase, puzzle[n]);
    }

    return 0;
}
