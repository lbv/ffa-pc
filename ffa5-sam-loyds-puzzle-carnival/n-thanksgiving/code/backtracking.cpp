#include <cstdio>
#include <cstring>


#define Back(b)    ((b) & -(b))
#define PopBack(b) (b &= ~Back(b))
#define Zero(v) memset((v), 0, sizeof(v))


typedef unsigned char uch;
typedef unsigned int  u32;


struct State {
    // bitmasks
    u32 used;
    u32 shots[3];

    int n;           // number of shots chosen
    int scores[3];   // partial scores for the players

    State() {
        used = 0;
        n = 0;
        Zero(shots);
        Zero(scores);
    }
};


int S[3];
int shots[18];

// bitmasks for the answer
u32 A, B, C;

const int pts[] = { 0, 1, 2, 3, 5, 10, 20, 25, 50 };
uch ctz[1 << 18];
const u32 all = (1 << 18) - 1;


bool solve(State s)
{
    if (s.n == 18) {
        A = s.shots[0];
        B = s.shots[1];
        C = s.shots[2];
        return true;
    }

    bool last_for_player = (s.n + 1) % 6 == 0;

    int idx = s.n / 6;

    for (u32 unused = all & ~s.used; unused != 0; PopBack(unused)) {
        u32 next = Back(unused);

        State s2 = s;
        s2.scores[idx] += shots[ctz[next]];

        if (s2.scores[idx] > S[idx]) break;
        if (last_for_player && s2.scores[idx] < S[idx]) continue;

        ++s2.n;
        s2.used |= next;

        s2.shots[idx] |= next;

        if (solve(s2)) return true;
    }

    return false;
}

void print_player(u32 bm)
{
    for (int i = 0; i < 6; ++i) {
        u32 b = Back(bm);
        PopBack(bm);
        printf("%s%d", i == 0 ? "" : " ", shots[ctz[b]]);
    }
    putchar('\n');
}

void print_shots()
{
    print_player(A);
    print_player(B);
    print_player(C);
}

void prepare()
{
    for (int i = 0; i < 18; ++i)
        ctz[1 << i] = i;
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d%d%d", &S[0], &S[1], &S[2]);

        int nshots = 0;
        for (int i = 0; i < 9; ++i) {
            int n;
            scanf("%d", &n);

            while (n--)
                shots[nshots++] = pts[i];
        }

        State s;
        solve(s);

        printf("Case %d:\n", ++ncase);
        print_shots();
    }

    return 0;
}
