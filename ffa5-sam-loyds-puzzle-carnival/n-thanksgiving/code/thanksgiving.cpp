#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


#define Zero(v) memset((v), 0, sizeof(v))


// Represents the six shots of a single player
struct Game {
    int s[6];
    Game() { Zero(s); }
};
typedef vector<Game> GV;


const int pts[] = { 0, 1, 2, 3, 5, 10, 20, 25, 50 };
const int sz_shots = sizeof(int) * 9;

int shots[9];
int S[3];
GV games[301];

Game A, B, C;


void print_game(const Game &g)
{
    for (int i = 0; i < 6; ++i)
        printf("%s%d", i == 0 ? "" : " ", pts[g.s[i]]);
    putchar('\n');
}

void prepare()
{
    int n = 0;
    for (int a = 0; a < 9; ++a)
        for (int b = a; b < 9; ++b)
            for (int c = b; c < 9; ++c)
                for (int d = c; d < 9; ++d)
                    for (int e = d; e < 9; ++e)
                        for (int f = e; f < 9; ++f) {
                            int score = pts[a] + pts[b] + pts[c] + pts[d] +
                                pts[e] + pts[f];

                            Game g;
                            g.s[0] = a;
                            g.s[1] = b;
                            g.s[2] = c;
                            g.s[3] = d;
                            g.s[4] = e;
                            g.s[5] = f;

                            games[score].push_back(g);
                            ++n;
                        }
}

void solve()
{
    for (int i = 0, I = games[S[0]].size(); i < I; ++i)
        for (int j = 0, J = games[S[1]].size(); j < J; ++j)
            for (int k = 0, K = games[S[2]].size(); k < K; ++k) {
                int comb[9] = { 0 };

                for (int m = 0; m < 6; ++m) {
                    ++comb[ games[S[0]][i].s[m] ];
                    ++comb[ games[S[1]][j].s[m] ];
                    ++comb[ games[S[2]][k].s[m] ];

                    if (memcmp(comb, shots, sz_shots) == 0) {
                        A = games[S[0]][i];
                        B = games[S[1]][j];
                        C = games[S[2]][k];
                        return;
                    }
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
        scanf("%d%d%d", &S[0], &S[1], &S[2]);

        for (int i = 0; i < 9; ++i)
            scanf("%d", &shots[i]);

        solve();

        printf("Case %d:\n", ++ncase);
        print_game(A);
        print_game(B);
        print_game(C);
    }

    return 0;
}
