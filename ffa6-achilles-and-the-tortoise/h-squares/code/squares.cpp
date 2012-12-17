#include <cstdio>
#include <cstring>


#define MAXN  15
#define MAXSQ 60000

#define Zero(v) memset((v), 0, sizeof(v))


int N, K;
int X;

int sq[MAXN][MAXN];
int S[MAXN-2][2];

int srow[MAXN];
int scol[MAXN];

bool vis[MAXSQ + 1];


void solve()
{
    Zero(srow);
    Zero(scol);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            srow[i] += sq[i][j];
            scol[j] += sq[i][j];
        }

    Zero(vis);
    for (int i = 0; i < N; ++i) {
        if (vis[srow[i]]) {
            X = srow[i];
            break;
        }
        vis[srow[i]] = true;
    }


    for (int i = 0; i < N; ++i) {
        int diff;

        diff = srow[i] - X;
        for (int j = 0; j < K; ++j)
            if (diff & (1 << j))
                S[j][0] = i + 1;

        diff = scol[i] - X;
        for (int j = 0; j < K; ++j)
            if (diff & (1 << j))
                S[j][1] = i + 1;
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &N, &K);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                scanf("%d", &sq[i][j]);

        solve();
        printf("Case %d: %d\n", ++ncase, X);
        for (int i = 0; i < K; ++i)
            printf("%d %d\n", S[i][0], S[i][1]);
    }

    return 0;
}
