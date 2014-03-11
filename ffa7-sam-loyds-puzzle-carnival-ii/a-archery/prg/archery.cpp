#include <cstdio>
#include <cstring>


#define MAXN 50
#define MAXS 300

#define Memset(m,v) memset(m, v, sizeof(m))
#define Neg(m) Memset(m,-1)


int P[MAXN];
int N, S;

// dp[i][j]: index of the last arrow used to achieve j points after i turns
int dp[MAXS + 1][MAXS + 1];


void print_arrows(int i, int j)
{
	if (dp[i][j] == N) return;

	printf(" %d", P[dp[i][j]]);

	print_arrows(i - 1, j - P[dp[i][j]]);
}

void solve()
{
	Neg(dp);
	dp[0][0] = N;

	for (int i = 1; i <= S; ++i)
		for (int j = N - 1; j >= 0; --j) {
			for (int k = P[j], p = 0; k <= S ; ++k, ++p)
				if (dp[i][k] < 0 && dp[i-1][p] >= 0)
					dp[i][k] = j;

			if (dp[i][S] >= 0) {
				printf("[%d]", i);
				print_arrows(i, S);
				puts("");
				return;
			}
		}

	puts("impossible");
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d", &N, &S);

		for (int i = 0; i < N; ++i) scanf("%d", &P[i]);

		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
