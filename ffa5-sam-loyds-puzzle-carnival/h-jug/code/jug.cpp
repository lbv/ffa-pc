#include <cstdio>
#include <cstdlib>
#include <cstring>


#define MAXLEN 50
#define MOD    1000000007

#define Zero(v) memset((v), 0, sizeof(v))


typedef long long i64;


// dp[i][j][k] has the number of ways in which the string word(0 .. k) can
// be formed in the grid, finishing at position (i, j)
int dp[MAXLEN][MAXLEN][MAXLEN];

char word[MAXLEN + 1];
char grid[MAXLEN][MAXLEN];
int len, k;


bool valid_pos(int r, int c)
{
    return r >= 0 && r < len && c >= 0 && c < len;
}

int solve()
{
    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j) {
            int d = abs(k - i) + abs(k - j);

            if (d > k) grid[i][j] = ' ';
            else grid[i][j] = word[k - d];
        }

    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j)
            dp[i][j][0] = grid[i][j] == word[0] ? 1 : 0;

    for (int x = 1; x <= k; ++x)
        for (int i = 0; i < len; ++i)
            for (int j = 0; j < len; ++j) {
                dp[i][j][x] = 0;

                for (int di = i - 1; di <= i + 1; ++di)
                    for (int dj = j - 1; dj <= j + 1; ++dj) {
                        if ((di == i && dj == j) ||
                            ! valid_pos(di, dj)) continue;
                        if (grid[i][j] == word[x]) {
                            dp[i][j][x] += dp[di][dj][x - 1];
                            dp[i][j][x] %= MOD;
                        }
                    }
            }

    int ans = 0;

    for (int i = 0; i < len; ++i)
        for (int j = 0; j < len; ++j) {
            i64 n = dp[i][j][k];

            if (n > 0) {
                n *= n;
                n %= MOD;
                ans += n;
                ans %= MOD;
            }
        }

    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%s", word);
        len = strlen(word);
        k = (len - 1) / 2;

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
