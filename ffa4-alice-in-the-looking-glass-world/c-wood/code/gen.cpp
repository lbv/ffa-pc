#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
using namespace std;


#define MAXT 30
#define MAXN 10000
#define MAXD 1000000

#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)


int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }


struct Vector {
    int x, y;
    double a;
    Vector() {}
    Vector(int X, int Y) : x(X), y(Y) {
        int g = gcd(x, abs(y));
        x /= g;
        y /= g;
        a = atan2(y, x);
    }
    bool operator==(const Vector &v) const { return x==v.x && y==v.y; }
    bool operator<(const Vector &v) const { return a < v.a; }
};
typedef vector<Vector> VV;

typedef pair<int, int> II;
typedef set<II>        IIS;

void test_case(int fixed_n = 0)
{
    int N = rand() % (MAXN - 3) + 4;
    if (fixed_n != 0) N = fixed_n;

    VV vs;
    IIS vis;

    N /= 2;

    int rem_h = MAXD - 1;
    int rem_v = MAXD - 1;

    for (int i = 0; i < N; ++i) {
        Vector v;
        II tuple;
        do {
            int x = rand() % (rem_h / (N - i)) + 1;
            int y = rand() % (rem_v / (N - i)) + 1;

            if (rand() % 2 == 0) y *= -1;
            v = Vector(x, y);
            tuple = II(v.x, v.y);
        } while (vis.find(tuple) != vis.end());

        vis.insert(tuple);
        vs.push_back(v);

        rem_h -= v.x;
        rem_v -= abs(v.y);
    }

    sort(vs.begin(), vs.end());

    printf("%d\n", N*2);

    int x, y;
    x = -MAXD / 2;
    y = 0;
    cFor (VV, v, vs) {
        x += v->x;
        y += v->y;
        printf("%d %d\n", x, y);
    }
    cFor (VV, v, vs) {
        x -= v->x;
        y -= v->y;
        printf("%d %d\n", x, y);
    }
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf(
"3\n"
"0 0\n"
"10 0\n"
"0 20\n"
"3\n"
"-1000000 42\n"
"1000000 42\n"
"144 1003\n"
"4\n"
"0 0\n"
"1 0\n"
"1 1\n"
"0 1\n"
"5\n"
"-100 -10\n"
"110 0\n"
"150 100\n"
"20 300\n"
"-200 80\n"
);
    T -= 4;

    test_case(4); --T;
    test_case(6); --T;
    test_case(16); --T;
    test_case(MAXN); --T;

    while (T--) test_case();

    return 0;
}
