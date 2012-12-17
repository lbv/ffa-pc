#include <cstdio>
#include <cstring>


#define MAXLEN 200

#define Zero(v) memset((v), 0, sizeof(v))


int C;
bool vis[26];
char s[MAXLEN + 1];


int solve()
{
    Zero(vis);
    int len = strlen(s);

    int clients = 0;
    int ans = 0;
    for (int i = 0; i < len; ++i) {
        int x = s[i] - 'A';
        if (vis[x]) {
            --clients;
            vis[x] = false;
        }
        else {
            ++clients;
            vis[x] = true;
            if (clients > C) ++ans;
        }
    }
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%s", &C, s);
        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
