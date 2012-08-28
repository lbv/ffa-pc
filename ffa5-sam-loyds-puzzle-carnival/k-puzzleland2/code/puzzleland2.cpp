#include <cstdio>
#include <deque>
using namespace std;


#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)


typedef long long i64;

typedef deque<char> CD;


i64 N;
CD sol;

void solve()
{
    sol.clear();
    if (N == 0) {
        sol.push_front('0');
        return;
    }

    while (N != 0) {
        sol.push_front('0' + N % 6);
        N /= 6;
    }
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%lld", &N);
        solve();

        printf("Case %d: ", ++ncase);
        cFor (CD, c, sol)
            putchar(*c);
        putchar('\n');
    }

    return 0;
}
