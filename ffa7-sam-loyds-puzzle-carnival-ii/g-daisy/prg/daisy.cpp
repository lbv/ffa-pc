#include <cstdio>
#include <cstring>


#define MAXN 20

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


int nim[MAXN + 1];
bool used[MAXN + 1];


int N, M;
bool petals[MAXN];  // true if it has been plucked

int s;  // index of some plucked petal to start the algorithm from there


void prepare()
{
	nim[1] = 1;
	nim[2] = 2;

	for (int i = 3; i <= MAXN; ++i) {
		Clr(used);

		for (int j = 0; j < i; ++j) {
			int g = nim[j] ^ nim[i - 1 - j];
			used[g] = true;

			if (j + 1 < i) {
				g = nim[j] ^ nim[i - 2 - j];
				used[g] = true;
			}
		}

		for (int j = 0; ; ++j)
			if (! used[j]) {
				nim[i] = j;
				break;
			}

	}
}

void solve()
{
	int g = 0;

	int sz = 0;
	for (int i = 0; i < N; ++i) {
		int p = (s + i) % N;

		if (petals[p]) {
			g ^= nim[sz];
			sz = 0;
		}
		else
			++sz;
	}
	g ^= nim[sz];

	if (g)
		puts("yes");
	else
		puts("no");
}

int main()
{
	prepare();

	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d", &N, &M);

		Clr(petals);
		for (int i = 0; i < M; ++i) {
			int p;
			scanf("%d", &p);
			petals[p - 1] = true;
			s = p-1;
		}

		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
