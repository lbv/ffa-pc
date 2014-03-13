#include <cstdio>
#include <set>
using namespace std;


#define MAXA 10000000

#define For(t,i,c) for(t::iterator i=(c).begin(); i != (c).end(); ++i)


typedef long long i64;


struct Triangle {
	i64 a, b, c;
	Triangle() {}
	Triangle(i64 A, i64 B, i64 C): a(A), b(B), c(C) {
		if (a > b) swap(a, b);
	}

	i64 area() const { return a*b/2; }
	bool operator<(const Triangle &t) const {
		if (a != t.a) return a < t.a;
		if (b != t.b) return b < t.b;
		return c < t.c;
	}
	void print() const {
		printf("(%lld,%lld,%lld)\n", a, b, c);
	}
};


set<Triangle> tri[MAXA + 1];
int A;


template<typename T>
T gcd(T a, T b) { for (T c = a%b; c != 0; a=b,b=c,c=a%b); return b; }


void prepare()
{
	for (i64 m = 2; ; ++m) {
		int cnt = 0;

		for (i64 n = 1; n < m; ++n) {
			if (gcd(m, n) != 1) continue;

			i64 a = m*m - n*n;
			i64 b = 2*m*n;
			i64 c = m*m + n*n;

			for (i64 k = 1; ; ++k) {
				Triangle t(k*a, k*b, k*c);
				if (t.area() > MAXA) break;

				tri[t.area()].insert(t);
				++cnt;
			}
		}

		if (cnt == 0) break;
	}
}

void solve()
{
	printf("%d\n", tri[A].size());
	For (set<Triangle>, i, tri[A])
		i->print();
}

int main()
{
	prepare();

	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d", &A);
		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
