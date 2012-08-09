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
    double max_diam = 0;

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j) {
            double d = ps[i].distance(ps[j]);
            if (d > max_diam) max_diam = d;
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
