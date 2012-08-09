#include <cassert>
#include <cstdio>


#define MAXT 30
#define MAXN 10000

#define MINC (-1000000)
#define MAXC 1000000

typedef long long i64;
typedef int p_t;

struct Point {
    p_t x, y;
    Point() { x=y=0; }
    Point(p_t X, p_t Y) : x(X), y(Y) {}
    bool collinear(const Point &b, const Point &c) const {
        return (b.y - y) * (c.x - x) == (c.y - y) * (b.x - x);
    }
};

i64 cross(const Point &o, const Point &a, const Point &b) {
    i64 p1 = a.x - o.x;
    p1 *= b.y - o.y;
    i64 p2 = a.y - o.y;
    p2 *= b.x - o.x;
    return p1 - p2;
}


int N;

Point ps[MAXN];


int main()
{
    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    for (int t = 1; t <= T; ++t) {
        printf("Checking test case %d ..\n", t);
        scanf("%d", &N);
        assert(3 <= N && N <= MAXN);

        int x, y;
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &x, &y);
            assert(MINC <= x && x <= MAXC);
            assert(MINC <= y && y <= MAXC);
            ps[i] = Point(x, y);
        }

        for (int i = 0; i < N; ++i) {
            int a = i - 2;
            int b = i - 1;

            if (a < 0) a += N;
            if (b < 0) b += N;

            i64 c = cross(ps[a], ps[b], ps[i]);
            /*
            printf("  p %d (%d, %d) against %d(%d, %d) and %d(%d, %d)\n",
                   i, ps[i].x, ps[i].y,
                   a, ps[a].x, ps[a].y,
                   b, ps[b].x, ps[b].y);
                   */
            assert(c > 0);
            assert(! ps[i].collinear(ps[a], ps[b]));
        }
    }
    puts("OK");

    return 0;
}
