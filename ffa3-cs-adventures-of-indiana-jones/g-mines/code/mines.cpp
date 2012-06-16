#include <cassert>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define MAXT 100
#define MAXR 100
#define MAXC 100
#define MAXH 6

#define Zero(v) memset(v, 0, sizeof(v))

struct Node {
    int r, c;
    int s;   // number of steps taken
    int b;   // bitmask of children rescued
    Node(int R, int C, int S, int B) : r(R), c(C), s(S), b(B) {}
};
typedef queue<Node> NQ;

char map[MAXR][MAXC + 1];
int  hidx[MAXR][MAXC];   // maps positions to the children number in them

bool vis[1 << MAXH][MAXR][MAXC];

const int deltas[4][2] = {
    {  0,  1 },
    {  0, -1 },
    {  1,  0 },
    { -1,  0 }
};

int R, C, H, ans;

bool valid_pos(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C;
}

bool bfs(int r, int c)
{
    Node nd(r, c, 0, 0);
    NQ q;
    q.push(nd);

    Zero(vis);
    vis[0][r][c] = true;

    int rescued = (1 << H) - 1;  // bitmask for all the children
    while (! q.empty()) {
        nd = q.front(); q.pop();
        if (map[nd.r][nd.c] == 'I' && nd.b == rescued) {
            ans = nd.s;
            return true;
        }

        for (int i = 0; i < 4; ++i) {
            int r2 = nd.r + deltas[i][0];
            int c2 = nd.c + deltas[i][1];

            if (! valid_pos(r2, c2) || map[r2][c2] == '#') continue;

            int b = nd.b;
            if (map[r2][c2] == '@') b |= (1 << hidx[r2][c2]);

            if (vis[b][r2][c2]) continue;
            q.push(Node(r2, c2, nd.s + 1, b));
            vis[b][r2][c2] = true;
        }
    }

    return false;
}

bool solve()
{
    int r, c, numh, nums, numi;
    numh = nums = numi = 0;

    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            if (map[i][j] == 'S') {
                r = i, c = j;
                ++nums;
            }
            else if (map[i][j] == 'I') ++numi;
            else if (map[i][j] == '@') hidx[i][j] = numh++;
            else
                assert(map[i][j] == '.' || map[i][j] == '#');
        }

    assert(numh == H);
    assert(nums == 1);
    assert(numi == 1);

    return bfs(r, c);
}

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d", &R, &C, &H);
        assert(1 <= R && R <= MAXR);
        assert(1 <= C && C <= MAXC);
        assert(0 <= H && H <= MAXH);

        for (int i = 0; i < R; ++i)
            scanf("%s", map[i]);

        if (solve())
            printf("Case %d: %d\n", ++ncase, ans);
        else
            printf("Case %d: impossible\n", ++ncase);
    }

    return 0;
}
