#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;


typedef unsigned char      uch;
typedef unsigned int       u32;
typedef unsigned long long u64;



int gcd(int a, int b) { for (int c = a%b; c; a=b,b=c,c=a%b); return b; }

//
// Hash Map
//
#define HASHB 252144
//#define HASHB 1048756
struct HM {
    struct Datum {
        int f[2];
        int r, s;
        Datum(int p, int q) { f[0] = p; f[1] = q; r = s = 0; }
        Datum(int p, int q, int R, int S) : r(R), s(S) {
            f[0] = p; f[1] = q;
        }
        bool operator==(const Datum &x) const {
            return f[0] == x.f[0] && f[1] == x.f[1];
        }
    };
    typedef vector<Datum> DV; DV b[HASHB];

    u32 fnv_hash(const Datum &k, int len) const {
        uch *p = reinterpret_cast<uch*>(const_cast<int*>(&k.f[0]));
        u32 h = 2166136261U;
        for (int i = 0; i < len; ++i) h = (h * 16777619U ) ^ p[i];
        return h;
    }

    bool add(const Datum &k) {
        int i = fnv_hash(k, 2 * sizeof(int)) % HASHB;
        for (int j = 0, J = b[i].size(); j < J; ++j)
            if (b[i][j] == k) {
                if (k.r > 0 && k.s > 0 && k.r < b[i][j].r) {
                    b[i][j].r = k.r;
                    b[i][j].s = k.s;
                }
                return false;
            }

        b[i].push_back(k);
        return true;
    }

    void get(Datum &k) const {
        int i = fnv_hash(k, 2 * sizeof(int)) % HASHB;
        for (int j = 0, J = b[i].size(); j < J; ++j)
            if (b[i][j] == k) {
                k = b[i][j];
                return;
            }
    }
};


HM hm;


void prepare()
{
    int dig[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    do {
        for (int i = 1; i <= 8; ++i) {
            int r = 0;
            for (int j = 0; j < i; ++j) { r *= 10; r += dig[j]; }
            int s = 0;
            for (int j = i; j < 9; ++j) { s *= 10; s += dig[j]; }

            if (r >= s) continue;

            int g = gcd(r, s);

            int p = r / g;
            int q = s / g;

            hm.add(HM::Datum(p, q, r, s));
        }
    } while (next_permutation(dig, dig + 9));
}

int main()
{
    prepare();

    int T;
    scanf("%d", &T);

    int ncase = 0;
    while (T--) {
        int p, q;
        scanf("%d/%d", &p, &q);

        int g = gcd(p, q);
        p /= g;
        q /= g;

        HM::Datum d(p, q);
        hm.get(d);

        printf("Case %d: ", ++ncase);

        if (d.r > 0 && d.s > 0)
            printf("%d %d\n", d.r, d.s);
        else
            puts("impossible");
    }

    return 0;
}
