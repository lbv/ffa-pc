#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <map>
#include <vector>
using namespace std;


#define MAXT 10000
#define MAXA 10000000


typedef long long i64;


map<int, int> area_cnt;
vector<int> as;
int n_areas;
int T;


template<typename T>
T gcd(T a, T b) { for (T c = a%b; c != 0; a=b,b=c,c=a%b); return b; }


void test_case()
{
	int A = rand() % MAXA + 1;
	printf("%d\n", A);
	--T;
}

void test_g()
{
	int i = rand() % n_areas;
	printf("%d\n", as[i]);
	--T;
}

void test_fixed(int A)
{
	printf("%d\n", A);
	--T;
}

void prepare()
{
	n_areas = 0;
	for (i64 m = 2; ; ++m) {
		int cnt = 0;

		for (i64 n = 1; n < m; ++n) {
			if (gcd(m, n) != 1) continue;

			i64 a = m*m - n*n;
			i64 b = 2*m*n;

			for (i64 k = 1; ; ++k) {
				i64 area = k*k*a*b/2;
				if (area > MAXA) break;

				if (area_cnt[area] == 0) {
					as.push_back(area);
					++n_areas;
				}
				++area_cnt[area];
				++cnt;
			}
		}

		if (cnt == 0) break;
	}
}

int main()
{
	prepare();

	srand(time(NULL));

	T = MAXT;
	printf("%d\n", T);

	for (int i = 0; i < 20; ++i) {
		test_fixed(i + 1);
		test_fixed(MAXA - i);
	}

	test_fixed(3360);
	test_fixed(1367520);

	while (T) {
		int r = rand() % 10;
		if (r < 8) test_g();
		else test_case();
	}

	return 0;
}
