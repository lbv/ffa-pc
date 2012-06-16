#include <cassert>
#include <cstdio>

#define MAXT 100
#define MAXN 1000

// dp[i][j] will have the probability of having a maximum chain of
// j in i consecutive planks
double dp[MAXN + 1][MAXN + 1];

// pp[i] will have p^i
double pp[MAXN + 1];

int N;
double p;
double ans;

void run_dp()
{
    pp[0] = 1.0;
    for (int i = 1; i <= N; ++i) pp[i] = pp[i - 1] * p;

    for (int j = 0; j <= N; ++j)
        dp[0][j] = 1.0;

    for (int i = 1; i <= N; ++i)
        for (int j = 0; j <= N; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j == i - 1) dp[i][j] -= pp[i];
            else if (j < i - 1)
                dp[i][j] -= dp[i - j - 2][j] * (1-p) * pp[j+1];
        }

    ans = 0.0;
    for (int j = 1; j <= N; ++j)
        ans += j * (dp[N][j] - dp[N][j - 1]);
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%lf", &N, &p);
        assert(1 <= N && N <= MAXN);
        assert(0 <= p && p <= 1.0);

        run_dp();

        printf("Case %d: %.3lf\n", ++ncase, ans);
    }

    return 0;
}
