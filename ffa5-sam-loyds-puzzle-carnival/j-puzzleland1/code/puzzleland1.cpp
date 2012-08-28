#include <algorithm>
#include <cstdio>
using namespace std;


#define MAXK 200
#define MAXS 2000
#define MINS -2000
#define MOD  1000000007


const int MAXSC = MAXS - MINS + 1;

// dp[i][j] has the number of ways to score i points with j dice
int dp[MAXSC][MAXK + 1];

// holds all the possible scores that can be made with a single die
int scores[24];
int nscores;

int K, S;

// Since there are negative scores, we need a way to convert negative
// values to correct positions inside the dp matrix
#define Idx(score) ((score) - MINS)


void run_dp()
{
    nscores = 0;
    for (int i = 1; i <= 6; ++i) {
        int total = 21 - (7 - i);
        for (int j = 1; j <= 6; ++j) {
            if (j == i || j == 7 - i) continue;

            int score = i + j - (total - i - j);
            scores[nscores++] = score;
        }
    }

    dp[Idx(0)][0] = 1;

    for (int k = 1; k <= MAXK; ++k)
        for (int i = 0; i < nscores; ++i) {
            int sc = scores[i];

            int from = max(MINS, MINS + sc);
            int to   = min(MAXS, MAXS + sc);

            for (int s = from; s <= to; ++s) {
                dp[Idx(s)][k] += dp[Idx(s - sc)][k - 1];
                dp[Idx(s)][k] %= MOD;
            }
        }
}

int main()
{
    run_dp();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &K, &S);

        printf("Case %d: %d\n", ++ncase, dp[Idx(S)][K]);
    }

    return 0;
}
