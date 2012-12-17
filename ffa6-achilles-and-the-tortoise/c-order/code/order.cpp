#include <cstdio>
#include <list>
using namespace std;


#define MAXN 100

#define For(t,i,c) for(t::iterator i=(c).begin(); i != (c).end(); ++i)


typedef list<int> IL;
typedef IL::iterator ILi;


int N;
int order[MAXN];
IL sol;


bool solve()
{
    sol = IL();
    for (int i = N - 1; i >= 0; --i) {
        int sz = sol.size();
        if (order[i] > sz) return false;

        ILi it = sol.begin();
        for (int j = 0; j < order[i]; ++j) ++it;
        sol.insert(it, i + 1);
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%d", &order[i]);

        printf("Case %d:", ++ncase);

        if (solve()) {
            For (IL, n, sol)
                printf(" %d", *n);
            putchar('\n');
        }
        else
            puts(" impossible");
    }

    return 0;
}
