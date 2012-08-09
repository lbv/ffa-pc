#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

#define MAXLEN 300

#define Zero(v) memset((v), 0, sizeof(v))

char A[MAXLEN + 1];
char B[MAXLEN + 1];
int a, b;  // length of strings

// dp[i][j] contains the length of the LCS from A(0, i) and B(0, j)
int dp[MAXLEN + 1][MAXLEN +1];

int solve()
{
    Zero(dp);

    for (int i = 1; i <= a; ++i)
        for (int j = 1; j <= b; ++j) {
            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }

    int l = dp[a][b];
    return (a - l) + (b - l);
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%s%s", A, B);
        a = strlen(A);
        b = strlen(B);

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
