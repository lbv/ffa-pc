#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


#define MAXN 100

#define Zero(v) memset((v), 0, sizeof(v))
#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)


struct Move {
    int p1, p2;
    Move(int P1, int P2) : p1(P1), p2(P2) {}
};
typedef vector<Move> MV;


// sg[i] is the Sprague-Grundy number for a row of i pins
int sg[MAXN + 1];

// pin i belongs to the group of adjacent pins [ from[i] : to[i] ).
int from[MAXN];
int to[MAXN];

bool game[MAXN + 1];
bool vis[MAXN + 1];

int N, K;

MV sol;

void prepare()
{
    sg[1] = 1;

    for (int i = 2; i <= MAXN; ++i) {
        Zero(vis);

        for (int j = 0; j < i; ++j) {
            int nim = sg[j] ^ sg[i - j - 1];
            vis[nim] = true;
        }

        for (int j = 0; j < i - 1; ++j) {
            int nim = sg[j] ^ sg[i - j - 2];
            vis[nim] = true;
        }

        int nim = 0;
        for (; vis[nim]; ++nim) ;

        sg[i] = nim;
    }
}

void solve()
{
    sol.clear();
    Zero(from);
    Zero(to);

    for (int i = 0; i < N; ++i) {
        if (! game[i]) continue;

        for (int x = i; i < N && game[i]; ++i)
            from[i] = x;
    }

    for (int i = N - 1; i >= 0; --i) {
        if (! game[i]) continue;

        for (int x = i; i >= 0 && game[i]; --i)
            to[i] = x + 1;
    }

    int nim = 0;
    for (int i = 0; i < N; ++i) {
        int adj = to[i] - from[i];

        if (adj > 0) {
            nim ^= sg[adj];
            i = to[i] - 1;
        }
    }

    for (int i = 0; i < N; ++i) {
        if (game[i]) {
            int n = nim;
            n ^= sg[ to[i] - from[i] ];
            n ^= sg[ i - from[i] ] ^ sg[ to[i] - (i + 1)];

            if (n == 0)
                sol.push_back(Move(i + 1, -1));
        }
    }

    for (int i = 0; i < N - 1; ++i) {
        if (game[i] && game[i + 1]) {
            int n = nim;
            n ^= sg[ to[i] - from[i] ];
            n ^= sg[ i - from[i] ] ^ sg[ to[i] - (i + 2)];

            if (n == 0)
                sol.push_back(Move(i + 1, i + 2));
        }
    }
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d", &N, &K);

        for (int i = 0; i < N; ++i)
            game[i] = true;

        while (K--) {
            int pin;
            scanf("%d", &pin);

            game[pin - 1] = false;
        }

        solve();

        printf("Case %d: %d\n", ++ncase, sol.size());
        cFor (MV, m, sol) {
            if (m->p2 >= 0)
                printf("(%d, %d)\n", m->p1, m->p2);
            else
                printf("(%d)\n", m->p1);
        }
    }

    return 0;
}
