#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

#define MAXT 200
#define MAXR 16
#define MAXC 16

#define Zero(v) memset((v), 0, sizeof(v))


struct Pos {
    int r, c;
    Pos() {}
    Pos(int R, int C) : r(R), c(C) {}
    bool operator==(const Pos &x) const {
        return r == x.r && c == x.c;
    }
    bool adjacent(const Pos &x) const {
        return ( r == x.r && abs(c - x.c) == 1 ) ||
            ( c == x.c && abs(r - x.r) == 1 );
    }
};

struct Node {
    Pos a, q;  // Alice, and the Queen
    int s;     // number of steps
    Node(Pos A, Pos Q, int S) : a(A), q(Q), s(S) {}
};
typedef queue<Node> NQ;


int R, C;
char grid[MAXR][MAXC + 1];
bool vis[MAXR][MAXC][MAXR][MAXC];


const int dd[4][2] = {
    { -1,  0 },  // north
    {  0,  1 },  // east
    {  1,  0 },  // south
    {  0, -1 }   // west
};


bool free_pos(int r, int c)
{
    return r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != '#';
}

int solve()
{
    Pos alice;
    Pos queen;

    int n_alice = 0;
    int n_queen = 0;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            assert(grid[i][j] == 'A' || grid[i][j] == 'Q' ||
                   grid[i][j] == '.' || grid[i][j] == '#');

            if (grid[i][j] == 'A') {
                alice = Pos(i, j);
                ++n_alice;
            }
            else if (grid[i][j] == 'Q') {
                queen = Pos(i, j);
                ++n_queen;
            }
        }
    assert(n_alice == 1 && n_queen == 1);

    NQ q;
    q.push(Node(alice, queen, 0));

    Zero(vis);
    vis[alice.r][alice.c][queen.r][queen.c] = true;

    while (! q.empty()) {
        Node nd = q.front(); q.pop();

        if (nd.a == nd.q || nd.a.adjacent(nd.q))
            return nd.s;

        for (int i = 0; i < 4; ++i) {
            int ar = nd.a.r + dd[i][0];
            int ac = nd.a.c + dd[i][1];

            if (! free_pos(ar, ac)) continue;

            int j = (i + 2) % 4;
            int qr = nd.q.r + dd[j][0];
            int qc = nd.q.c + dd[j][1];

            if (! free_pos(qr, qc)) qr = nd.q.r, qc = nd.q.c;

            if (vis[ar][ac][qr][qc]) continue;
            q.push(Node(Pos(ar, ac), Pos(qr, qc), nd.s + 1));
            vis[ar][ac][qr][qc] = true;
        }
    }

    return -1;
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
        assert(1 <= C && C <= MAXR);

        for (int i = 0; i < R; ++i)
            scanf("%s", grid[i]);

        printf("Case %d: ", ++ncase);

        int ans = solve();

        if (ans < 0)
            puts("impossible");
        else
            printf("%d\n", ans);
    }

    return 0;
}
