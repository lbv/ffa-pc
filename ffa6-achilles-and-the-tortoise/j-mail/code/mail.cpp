#include <cstdio>


#define MAXN 1000

int as[MAXN + 1];
int ts[MAXN + 1];
int N;
int house;


bool solve()
{
    for (int i = 1; i <= N; ++i)
        as[i] += as[i - 1];

    for (int i = N - 1; i >= 0; --i)
        ts[i] += ts[i + 1];

    for (int i = 0; i < N; ++i)
        if (as[i] == ts[i + 1]) {
            house = i + 1;
            return true;
        }

    return false;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i <= N; ++i) scanf("%d", &as[i]);
        for (int i = 0; i <= N; ++i) scanf("%d", &ts[i]);

        printf("Case %d: ", ++ncase);
        if (solve())
            printf("yes %d\n", house);
        else
            puts("no");
    }

    return 0;
}
