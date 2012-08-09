#include <cstdio>

int N;

int josephus(int n, int k, bool right)
{
    if (n == 1) return 0;
    if (right)
        return (josephus(n - 1, k + 1, false) + k) % n;
    int ans = (josephus(n - 1, k + 1, true) + n + 1 - k)  % n;
    return ans < 0 ? ans + n : ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);
        printf("Case %d: %d\n", ++ncase, josephus(N, 1, true) + 1);
    }

    return 0;
}
