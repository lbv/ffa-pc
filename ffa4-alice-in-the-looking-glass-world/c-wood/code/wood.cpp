#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

#define MAXN 10000


const double Pi_2 = acos(0.0);
const double Pi   = Pi_2*2;
const double Pi2  = Pi_2*4;

// Geometry
double circle_angle(double a) { return a >= 0 ? a : Pi2 + a; }

typedef long long i64;
typedef int p_t;
struct Point {
    p_t x, y;
    Point() { x=y=0; }
    Point(p_t X, p_t Y) : x(X), y(Y) {}
    double distance(Point p) {
        i64 dx = p.x - x, dy = p.y - y; return sqrt(dx*dx + dy*dy);
    }
    bool operator<(const Point &p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
};
struct Vector {
    double x, y;
    Vector(double X, double Y) : x(X), y(Y) {}
    Vector(const Point &p) : x(p.x), y(p.y) {}
    double angle(const Vector &p) const {
        return circle_angle(atan2(p.y, p.x) - atan2(y, x));
    }
    void rotate(double a) {
        double px = x, py = y;
        x = px*cos(a) - py*sin(a);
        y = px*sin(a) + py*cos(a);
    }
};


Point ps[MAXN];
int N;


#define Next(idx) ((idx) + 1 < N ? (idx) + 1 : 0)

double solve()
{
    int a, b;
    a = b = 0;

    for (int i = 1; i < N; ++i) {
        if (ps[i].y < ps[a].y) a = i;
        if (ps[i].y > ps[b].y) b = i;
    }

    double max_diam = ps[a].distance(ps[b]);

    // calipers
    Vector ca(1, 0), cb(-1, 0);

    double rotated = 0.0;

    while (rotated <= Pi) {
        int a2=Next(a), b2=Next(b);

        Vector ea(ps[a2] - ps[a]), eb(ps[b2] - ps[b]);

        double aa = ca.angle(ea);
        double ab = cb.angle(eb);

        double mina = min(aa, ab);
        ca.rotate(mina);
        cb.rotate(mina);

        if (aa == mina) a = a2;
        if (ab == mina) b = b2;

        double diam = ps[a].distance(ps[b]);
        if (diam > max_diam) max_diam = diam;

        rotated += mina;
    }

    return max_diam;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);

        int x, y;
        for (int i = 0; i < N; ++i) {
            scanf("%d%d", &x, &y);
            ps[i] = Point(x, y);
        }

        printf("Case %d: %.3lf\n", ++ncase, solve());
    }

    return 0;
}
