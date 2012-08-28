#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
using namespace std;


#define MAXC 50
#define MAXM 20

#define Zero(v) memset((v), 0, sizeof(v))


typedef pair<char, char> CC;


struct Trail {
    struct Node {
        int parent;
        CC move;
        Node(int P, CC M) : parent(P), move(M) {}
    };
    vector<Node> tree;
    int idx;
    Trail() { idx = 0; }
    int add(char from, char to, int prev = -1) {
        tree.push_back(Node(prev, CC(from, to)));
        return idx++;
    }
};

struct Node {
    int a, b, c, d, t;
    Node (int A, int B, int C, int D, int T) : a(A), b(B), c(C), d(D), t(T) {}
};
typedef queue<Node> NQ;


bool vis[MAXC + 1][MAXC + 1][MAXM + 1][MAXM + 1];
int C, M1, Q1, M2, Q2;
string sol;
Trail trail;
const char containers[] = "abcd";

void set_solution(int n)
{
    sol.clear();
    stack<CC> s;

    for (; n >= 0; n = trail.tree[n].parent)
        s.push(trail.tree[n].move);

    if (! s.empty()) {
        sol.push_back(s.top().first);
        sol.push_back(s.top().second);
        s.pop();
    }
    while (! s.empty()) {
        sol.push_back(',');
        sol.push_back(s.top().first);
        sol.push_back(s.top().second);
        s.pop();
    }
}

bool solve()
{
    NQ q;
    q.push(Node(C, C, 0, 0, -1));

    Zero(vis);
    vis[C][C][0][0] = true;

    trail = Trail();

    int cap[] = { C, C, M1, M2 };

    while (! q.empty()) {
        Node nd = q.front(); q.pop();

//        printf("  ~~ %d %d %d %d\n", nd.a, nd.b, nd.c, nd.d);
        if (nd.c == Q1 && nd.d == Q2) {
            set_solution(nd.t);
            return true;
        }

        for (int src = 0; src < 4; ++src)
            for (int dst = 0; dst < 4; ++dst) {
                if (src == dst) continue;

                int mlk[] = { nd.a, nd.b, nd.c, nd.d };

                int qt = min(mlk[src], cap[dst] - mlk[dst]);

                mlk[src] -= qt;
                mlk[dst] += qt;

                if (vis[mlk[0]][mlk[1]][mlk[2]][mlk[3]]) continue;

                int t = trail.add(containers[src], containers[dst], nd.t);
                Node nd2(mlk[0], mlk[1], mlk[2], mlk[3], t);

                vis[nd2.a][nd2.b][nd2.c][nd2.d] = true;
                q.push(nd2);
            }
    }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d%d%d", &C, &M1, &Q1, &M2, &Q2);

        printf("Case %d: ", ++ncase);

        if (solve())
            printf("%s\n", sol.c_str());
        else
            puts("impossible");
    }

    return 0;
}
