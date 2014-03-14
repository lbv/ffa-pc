#include <cstdio>


#define MAXN 8


typedef long long i64;


int N;
i64 M[MAXN];


template<typename T>
T gcd(T a, T b) { for (T c = a%b; c != 0; a=b,b=c,c=a%b); return b; }

i64 solve()
{
	i64 lcm = M[0];

	for (int i = 1; i < N; ++i) {
		i64 g = gcd(lcm, M[i]);
		lcm = lcm / g * M[i];
	}

	return lcm * (5 + 10 + 20);
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lld", &M[i]);

		printf("Case %d: %lld\n", ++ncase, solve());
	}

	return 0;
}
