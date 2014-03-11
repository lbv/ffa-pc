#include <cstdio>
#include <cstring>


#define MAXN 50
#define MAXS 300

#define Memset(m,v) memset(m, v, sizeof(m))
#define Clr(m) Memset(m,0)


struct State {
	int s;  // total score
	int n;  // number of arrows used
	int p;  // point of last arrow
	int u;  // index of previous state

	State() {}
	State(int S, int N, int P, int U): s(S), n(N), p(P), u(U) {}
};


State q[MAXS + 1];
bool vis[MAXS + 1];

int P[MAXN];
int N, S;


void print_arrows(int i)
{
	if (q[i].p < 0) return;

	print_arrows(q[i].u);
	printf(" %d", q[i].p);
}

void solve()
{
	Clr(vis);
	int n = 0;

	q[n++] = State(0, 0, -1, -1);

	for (int i = 0; i < n; ++i) {
		State &s = q[i];

		if (s.s == S) {
			printf("[%d]", s.n);
			print_arrows(i);
			puts("");
			return;
		}

		for (int j = N - 1; j >= 0; --j) {
			int new_score = s.s + P[j];

			if (new_score > S || vis[new_score]) continue;
			vis[new_score] = true;
			q[n++] = State(new_score, s.n + 1, P[j], i);
		}
	}

	puts("impossible");
}

int main()
{
	int T;
	scanf("%d", &T);

	int ncase = 0;
	while (T--) {
		scanf("%d%d", &N, &S);

		for (int i = 0; i < N; ++i) scanf("%d", &P[i]);

		printf("Case %d: ", ++ncase);
		solve();
	}

	return 0;
}
