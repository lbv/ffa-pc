#include <algorithm>
#include <cstdio>
#include <cstring>
#include <list>
#include <set>
#include <vector>
using namespace std;


#define MAXN   100
#define MAXM   1000
#define MAXL   100000
#define MAXLEN 10

const int INF = MAXM * MAXL + 100;

#define For(t,i,c) for(t::iterator i=(c).begin(); i != (c).end(); ++i)
#define Zero(v) memset((v), 0, sizeof(v))


typedef vector<bool> BV;
typedef vector<int>  IV;


// Weighted adjacency lists
typedef int w_t;
struct Graph {
    struct Edge { int v; w_t w; Edge(int V, w_t W) : v(V), w(W) {} };
    typedef list<Edge> EL;
    typedef vector<EL> ELV;
    ELV adj; int n;
    Graph(int N) : n(N) { adj.resize(n); }
    void add(int u, int v, w_t w) { adj[u].push_back(Edge(v, w)); }

    struct Node {
        int d, u, v;
        Node(int D, int U, int V) : d(D), u(U), v(V) {}
        bool operator<(const Node &x) const { return d < x.d; }
    };

    void prim_mst(int src, Graph &mst) {
        multiset<Node> q;
        IV dis(n, INF);
        BV flg(n);
        dis[src] = 0;
        q.insert(Node(0, src, src));

        while (! q.empty()) {
            Node nd = *(q.begin());
            q.erase(q.begin());

            int d = nd.d, u = nd.u, v = nd.v;
            if (flg[v]) continue;
            flg[v] = true;

            if (u != v) {
                mst.add(u, v, d);
                mst.add(v, u, d);
            }

            For (EL, e, adj[v])
                if (!flg[e->v] && e->w < dis[e->v]) {
                    dis[e->v] = e->w;
                    q.insert(Node(e->w, v, e->v));
                }
        }
    }
};


int N, M, Q;
int L;
char A[MAXLEN + 1];
char B[MAXLEN + 1];

char cities[MAXN][MAXLEN + 1];
int ncities;

bool vis[MAXN];


int city_id(const char *c)
{
    for (int i = 0; i < ncities; ++i)
        if (strcmp(cities[i], c) == 0) return i;

    strcpy(cities[ncities], c);
    return ncities++;
}

bool dfs(Graph &g, int v, int dest)
{
    vis[v] = true;
    if (v == dest) return true;

    For (Graph::EL, e, g.adj[v]) {
        if (vis[e->v]) continue;
        if (dfs(g, e->v, dest)) {
            printf("%s %s (%d)\n", cities[e->v], cities[v], e->w);
            return true;
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
        scanf("%d%d", &N, &M);

        Graph g(N);
        ncities = 0;

        while (M--) {
            scanf("%s%s%d", A, B, &L);
            int u = city_id(A);
            int v = city_id(B);

            g.add(u, v, L);
            g.add(v, u, L);
        }

        Graph mst(N);
        g.prim_mst(0, mst);

        printf("Case %d:\n", ++ncase);
        scanf("%d", &Q);

        for (int q = 1; q <= Q; ++q) {
            scanf("%s%s", A, B);
            int s = city_id(A);
            int e = city_id(B);

            printf("* Query %d\n", q);
            Zero(vis);
            dfs(mst, e, s);
        }
    }

    return 0;
}
