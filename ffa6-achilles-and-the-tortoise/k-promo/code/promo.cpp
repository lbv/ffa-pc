#include <algorithm>
#include <cstdio>
using namespace std;


#define MAXN 1000


int N;
int vs[MAXN];

// dp[i]: maximum sum over subsequence of items that end in position i
int dp[MAXN];


int solve()
{
    for (int i = 0; i < N; ++i) {
        int best = vs[i];

        for (int j = 0; j < i; ++j)
            if (vs[j] < vs[i])
                best = max(best, dp[j] + vs[i]);

        dp[i] = best;
    }

    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (dp[i] > ans) ans = dp[i];

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &vs[i]);

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
