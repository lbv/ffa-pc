#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;


#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)

#define Abs(x) fabs(x)


#define MAX_ROWS 3
#define MAX_COLS 4

template <typename T>
struct Matrix {
	int r, c;
	T m[MAX_ROWS][MAX_COLS];
	Matrix(int R, int C) : r(R), c(C) {}

	bool gaussian() {
		for (int k = 0; k < r; ++k) {
			int im = k; T v=Abs(m[k][k]);
			for (int i = k + 1; i < r; ++i)
				if (Abs(m[i][k]) > v) v = Abs(m[i][k]), im = i;
			if (v == 0) return false;
			swap(m[k], m[im]);
			for (int i = k + 1; i < r; ++i) {
				for (int j = k + 1; j < c; ++j)
					m[i][j] -= m[k][j] * (m[i][k] / m[k][k]);
				m[i][k] = 0;
			}
		}
		return true;
	}

	T memo[MAX_ROWS];
	bool vis[MAX_ROWS];
	T solve(int i) {
		if (vis[i]) return memo[i];
		T ans = m[i][c - 1] / m[i][i];
		for (int j = i + 1; j < r; ++j)
			if (m[i][j] != 0)
				ans -= solve(j) * m[i][j] / m[i][i];

		vis[i] = true;
		return memo[i] = ans;
	}
};


Matrix<double> mat(3, 4);


void print_matrix()
{
	puts("--");
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			printf(" %3.2lf", mat.m[i][j]);
		puts("");
	}
}

void solve()
{
	mat.gaussian();

	Clr(mat.vis);
	printf("%.2lf %.2lf %.2lf\n", mat.solve(0), mat.solve(1), mat.solve(2));
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%lf", &mat.m[i][j]);

		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
