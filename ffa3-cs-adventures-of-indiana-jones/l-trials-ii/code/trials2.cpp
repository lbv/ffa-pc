#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstring>

#define MAXT 500
#define MAXR 80
#define MAXC 80
#define MAXLEN 50

#define MOD 1000003

#define Zero(v) memset(v, 0, sizeof(v))

// dp[i][j] will have the number of ways to reach cell (i, j)
int dp[MAXR][MAXC];

char map[MAXR][MAXC + 1];
char word[MAXLEN + 1];
bool valid[26];
int ans;

int R, C;

void solve()
{
    Zero(dp);

    for (int j = 0; j < C; ++j)
        if (isalpha(map[R - 1][j]) && valid[map[R - 1][j] - 'A'])
            dp[R - 1][j] = 1;

    for (int i = R - 2; i >= 0; --i)
        for (int j = 0; j < C; ++j)
            if (isalpha(map[i][j]) && valid[map[i][j] - 'A']) {
                if (j > 0)
                    dp[i][j] += dp[i + 1][j - 1];
                if (j < C - 1)
                    dp[i][j] += dp[i + 1][j + 1];
                if (i < R - 2)
                    dp[i][j] += dp[i + 2][j];

                dp[i][j] %= MOD;
            }

    ans = 0;
    for (int j = 0; j < C; ++j)
        ans += dp[0][j];

    ans %= MOD;
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &R, &C);
        assert(1 <= R && R <= MAXR);
        assert(1 <= C && C <= MAXC);

        scanf("%s", word);
        int len = strlen(word);
        assert(1 <= len && len <= MAXLEN);

        Zero(valid);
        for (int i = 0; i < len; ++i) {
            assert(word[i] >= 'A' && word[i] <= 'Z');
            valid[word[i] - 'A'] = true;
        }

        for (int i = 0; i < R; ++i)
            scanf("%s", map[i]);

        solve();

        printf("Case %d: %d\n", ++ncase, ans);
    }

    return 0;
}
