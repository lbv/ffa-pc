#include <algorithm>
#include <cassert>
#include <cstdio>
#include <list>
#include <set>
#include <vector>
using namespace std;

#define MAXT 25
#define MAXN 1000
#define MAXM 10000
#define MAXD 100
#define MAXW 10000

#define INF 100000010

#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)

typedef vector<int> IV;
typedef vector<bool> BV;

typedef pair<int, int> II;

typedef set<II> IIS;

typedef II w_t;
struct Graph {
    struct Edge { int v; w_t w; Edge(int V, w_t W) : v(V), w(W) {} };
    typedef list<Edge> EL;
    typedef vector<EL> ELV;
    ELV adj; int n;
    void init(int N) { n=N; adj.clear(); adj.resize(n); }
    void add(int u, int v, w_t w) { adj[u].push_back(Edge(v, w)); }

    int dijkstra(int D) {
        IIS q;
        IV dis1(n, INF);
        IV dis2(n, INF);
        BV flg(n);

        dis1[0] = 0;
        dis2[0] = D;

        q.insert(II(0, 0));

        while (! q.empty()) {
            int v = q.begin()->second;
            if (v == n - 1)
                return q.begin()->first;

            q.erase(q.begin());

            if (flg[v]) continue;
            flg[v] = true;

            int d1 = min(dis1[v], dis2[v] + D);
            int d2 = min(dis1[v] + D, dis2[v]);

            cFor (EL, e, adj[v]) {
                int short1 = min(dis1[e->v], dis2[e->v]);

                if (d1 + e->w.first < dis1[e->v])
                    dis1[e->v] = d1 + e->w.first;
                if (d2 + e->w.second < dis2[e->v])
                    dis2[e->v] = d2 + e->w.second;

                int short2 = min(dis1[e->v], dis2[e->v]);

                if (short2 < short1)
                    q.insert(II(short2, e->v));
            }
        }
        return -1;
    }
};

int N, M, D;

int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d", &N, &M, &D);
        assert(2 <= N && N <= MAXN);
        assert(1 <= M && M <= MAXM);
        assert(1 <= D && D <= MAXD);

        Graph g;
        g.init(N);

        for (int i = 0; i < M; ++i) {
            int u, v, w1, w2;
            scanf("%d%d%d%d", &u, &v, &w1, &w2);
            assert(0 <= u && u < N);
            assert(0 <= v && v < N);
            assert(u != v);
            assert(1 <= w1 && w1 <= MAXW);
            assert(1 <= w2 && w2 <= MAXW);

            g.add(u, v, II(w1, w2));
            g.add(v, u, II(w1, w2));
        }

        int ans = g.dijkstra(D);
        assert(ans > 0);
        printf("Case %d: %d\n", ++ncase, ans);
    }

    return 0;
}
