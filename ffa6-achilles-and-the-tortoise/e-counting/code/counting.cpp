#include <cstdio>
#include <vector>
using namespace std;


typedef vector<int> IV;


#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
namespace Num
{
    const int MAX = 1000000;  // 10^6
    const int LMT =    1000;  // sqrt(MAX)
    int _c[(MAX>>6)+1];
    IV primes;
    void prime_sieve() {
        for (int i = 3; i <= LMT; i += 2)
            if (!IsComp(i)) for (int j = i*i; j <= MAX; j+=i+i) SetComp(j);
    }
    bool is_prime(int n) {
        if (n < 2 || (n > 2 && n % 2 == 0)) return false;
        return ! IsComp(n);
    }
};
using namespace Num;

//
// Segment Tree
//
#define MAXN 10000
#define MAXH 15  // 1 + ceil(log2(MAXN))
struct SegTree {
    struct Node {
        int v;   // tree value
        bool u;  // requires update
    };

    int A[MAXN + 1];
    Node T[1 << MAXH];
    int n;

    void init(int N) { n = N; tree_init(1, 0, n-1); }
    void tree_init(int x, int a, int b) {
        T[x].u = false;
        if (a == b) { T[x].v = A[a]; return; }
        int lt = 2*x, rt = lt + 1, md = (a+b)/2;
        tree_init(lt, a, md);
        tree_init(rt, md + 1, b);
        T[x].v = T[lt].v + T[rt].v;
    }

    void propagate(int x, int a, int b) {
        if (! T[x].u) return;
        if (a != b) {
            int lt = 2*x, rt = lt + 1;
            T[lt].u = T[rt].u = true;
            T[lt].v = T[rt].v = T[x].v;
        }
        T[x].v = T[x].v * (b - a + 1);
        T[x].u = false;
    }

    void update(int i, int j, int v) { tree_update(i, j, v, 1, 0, n-1); }
    void tree_update(int i, int j, int v, int x, int a, int b) {
        propagate(x, a, b);
        if (j < a || i > b) return;
        if (a == b) { T[x].v = v; return; }
        int lt = 2*x, rt = lt + 1, md = (a+b)/2;
        if (a >= i && b <= j) {
            T[x].v = v * (b - a + 1);
            T[lt].u = T[rt].u = true;
            T[lt].v = T[rt].v = v;
            return;
        }
        tree_update(i, j, v, lt, a, md);
        tree_update(i, j, v, rt, md + 1, b);
        T[x].v = T[rt].v + T[lt].v;
    }

    int query(int i, int j) { return tree_query(i, j, 1, 0, n-1); }
    int tree_query(int i, int j, int x, int a, int b) {
        if (j < a || i > b) return 0;
        propagate(x, a, b);
        if (a >= i && b <= j) return T[x].v;
        int lt = 2*x, rt = lt + 1, md = (a+b)/2;
        int q1 = tree_query(i, j, lt, a, md);
        int q2 = tree_query(i, j, rt, md + 1, b);
        return q1 + q2;
    }
};


int N, Q;
SegTree tree;


int main()
{
    prime_sieve();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        printf("Case %d:\n", ++ncase);
        scanf("%d%d", &N, &Q);
        for (int i = 1; i <= N; ++i) {
            int a;
            scanf("%d", &a);
            tree.A[i] = is_prime(a) ? 1 : 0;
        }
        tree.init(N + 1);

        while (Q--) {
            int op, i, j, x;
            scanf("%d", &op);

            if (op == 0) {
                scanf("%d%d%d", &i, &j, &x);
                tree.update(i, j, is_prime(x) ? 1 : 0);
            }
            else if (op == 1) {
                scanf("%d%d", &i, &j);
                printf("%d\n", tree.query(i, j));
            }
        }
    }

    return 0;
}
