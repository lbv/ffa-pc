#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;


#define MAXLEN 50
#define MAXN   100


typedef vector<int> IV;


// Union-Find disjoint set
struct Set {
    IV s;
    Set(int n) { for (int i=0; i <= n; ++i) s.push_back(i); }
    int find(int i) { if (s[i] == i) return i; return s[i]=find(s[i]); }
    void merge(int i, int j) { s[find(i)] = find(j); }
};


char object[MAXLEN + 1];
int vow[MAXN];
int con[MAXN];
int N;


// counts number of vowels and consonant of word
void count(const char *str, int &v, int &c)
{
    v = c = 0;
    for (int i = 0, I = strlen(str); i < I; ++i) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' ||
            str[i] == 'o' || str[i] == 'u')
            ++v;
        else
            ++c;
    }
}

int solve()
{
    Set s(N);

    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (vow[i] == vow[j] || con[i] == con[j])
                s.merge(i, j);

    int ans = 0;
    for (int i = 0; i < N; ++i)
        if (s.find(i) == i)
            ++ans;
    return ans;
}

int main()
{
    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        scanf("%d", &N);

        int v, c;
        for (int i = 0; i < N; ++i) {
            scanf("%s", object);
            count(object, v, c);
            vow[i] = v;
            con[i] = c;
        }

        printf("Case %d: %d\n", ++ncase, solve());
    }

    return 0;
}
