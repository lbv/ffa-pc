#include <cstdio>
#include <list>
using namespace std;


typedef list<int> IL;
typedef IL::iterator ILi;


IL seq;
int N;


ILi get_it(int i)
{
    ILi it = seq.begin();

    while (i--) ++it;

    return it;
}

int solve()
{
    seq.clear();

    for (int i = 1; i <= N; ++i)
        seq.push_back(i);

    bool right = true;
    int cnt = 1;
    int pos = -1;

    for (int sz = N; sz > 1; --sz) {
        if (right) pos += cnt;
        else pos -= cnt;

        pos %= sz;
        if (pos < 0) pos += sz;

        ILi it = get_it(pos);
        seq.erase(it);

        right = !right;
        ++cnt;

        if (right) --pos;
    }

    return seq.front();
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
