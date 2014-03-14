#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;


#define MAXT 5000
#define MAXN 15
#define MAXJ 222

#define EPS (1e-6)


bool eps_equal(double a, double b) { return fabs(a - b) < EPS; }


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
			if (eps_equal(v, 0)) return false;
			swap(m[k], m[im]);
			for (int i = k + 1; i < r; ++i) {
				for (int j = k + 1; j < c; ++j)
					m[i][j] -= m[k][j] * (m[i][k] / m[k][k]);
				m[i][k] = 0;
			}
		}
		return true;
	}
};


Matrix<double> mat(3, 4);

int T;


void gen_matrix()
{
	int s = rand() % MAXJ + 1;
	int m = rand() % MAXJ + 1;
	int l = rand() % MAXJ + 1;

	if (s > m) swap(s, m);
	if (s > l) swap(s, l);
	if (m > l) swap(m, l);

	for (int i = 0; i < 3; ++i) {
		int S, M, L;
		do {
			S = rand() % (MAXN + 1);
			M = rand() % (MAXN + 1);
			L = rand() % (MAXN + 1);
		} while (S == 0 && M == 0 && L == 0);

		double tot = 0.0;
		tot += S * (1.0 * s / 100.0);
		tot += M * (1.0 * m / 100.0);
		tot += L * (1.0 * l / 100.0);

		mat.m[i][0] = S;
		mat.m[i][1] = M;
		mat.m[i][2] = L;
		mat.m[i][3] = tot;
	}
}

void test_case()
{
	Matrix<double> tmp(3, 4);

	do {
		gen_matrix();
		tmp = mat;
	} while (! tmp.gaussian());

	puts("");
	for (int i = 0; i < 3; ++i) {
		printf("%.0lf %.0lf %.0lf %.2lf\n",
			mat.m[i][0], mat.m[i][1], mat.m[i][2], mat.m[i][3]);
	}

	--T;
}

void test_fixed(const char *s1, const char *s2, const char *s3)
{
	printf("\n%s\n%s\n%s\n", s1, s2, s3);
	--T;
}

int main()
{
	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	test_fixed("1 0 0 0.01", "0 1 0 0.01", "0 0 1 0.01");
	test_fixed("15 15 15 84.90", "1 3 5 18.54", "10 2 13 47.26");
	test_fixed("10 10 10 100.00", "0 1 1 8.50", "7 0 2 22.50");

	while (T) test_case();

	return 0;
}
