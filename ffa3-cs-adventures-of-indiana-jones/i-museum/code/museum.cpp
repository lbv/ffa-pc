#include <cassert>
#include <cstdio>
#include <cstring>

#define MAXT 500
#define MAXR 100
#define MAXC 100

#define Zero(v) memset(v, 0, sizeof(v))

int R, C;
char map[MAXR][MAXC + 1];
int ans;
bool vis[MAXR][MAXC];

bool valid_pos(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C;
}

void dfs(int r, int c)
{
    vis[r][c] = true;

    for (int i = -1; i <= 1; ++i) {
        int r2 = r + i;
        for (int j = -1; j <= 1; ++j) {
            int c2 = c + j;
            if (valid_pos(r2, c2) && map[r2][c2] == '@'
                && ! vis[r2][c2]) dfs(r2, c2);
        }
    }
}

void solve()
{
    ans = 0;

    Zero(vis);
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            assert(map[i][j] == '.' || map[i][j] == '@' || map[i][j] == '#');
            if (map[i][j] == '@' && ! vis[i][j]) {
                ++ans;
                dfs(i, j);
            }
        }
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

        for (int i = 0; i < R; ++i)
            scanf("%s", map[i]);

        solve();

        printf("Case %d: %d\n", ++ncase, ans);
    }

    return 0;
}
