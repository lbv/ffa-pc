#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;


typedef long long i64;

typedef vector<i64>  IV;
typedef IV::iterator IVi;


IV tri;  // triangular numbers
i64 N;


void prepare()
{
    for (i64 i = 1; i <= 1000000; ++i)
        tri.push_back(i * (i+1) / 2);
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%lld", &N);

        IVi it = upper_bound(tri.begin(), tri.end(), N);
        --it;

        i64 walrus = *it;
        i64 carp   = N - walrus;

        printf("Case %d: %lld %lld\n", ++ncase, walrus, carp);
    }

    return 0;
}
