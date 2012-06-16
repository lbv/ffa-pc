#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

#define MAXT 80
#define MAXI 1000000000000LL
#define MAXDIFF 1000000

#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)

typedef long long i64;

typedef vector<int>  IV;
typedef vector<bool> BV;

// Number Theory
#define IsComp(n)  (_c[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) _c[n>>6]|=(1<<((n>>1)&31))
namespace Num
{
    const int MAX = 1000000;  // 10^6
    const int LMT =    1000;  // sqrt(MAX)
    int _c[(MAX>>6)+1];
    IV primes;
    void prime_sieve() {
        for (int i = 3; i <= LMT; i += 2)
            if (!IsComp(i)) for (int j = i*i; j <= MAX; j+=i+i) SetComp(j);
        primes.push_back(2);
        for (int i=3; i <= MAX; i+=2) if (!IsComp(i)) primes.push_back(i);
    }
    // Finds prime numbers between a and b, using basic primes up to sqrt(b)
    void prime_seg_sieve(i64 a, i64 b, int &N) {
        BV pmap(b - a + 1, true);
        i64 sqr_b = sqrt(b);
        cFor (IV, pp, primes) {
            int p = *pp;
            if (p > sqr_b) break;
            for (i64 j = (a+p-1)/p, v=(j==1?p+p:j*p); v <= b; v += p)
                pmap[v-a] = false;
        }
        if (a == 1) pmap[0] = false;
        assert(pmap[0]);
        assert(pmap[b - a]);
        N = 0;
        for (int i = a%2 ? 0 : 1, I = b - a + 1; i < I; i += 2)
            if (pmap[i]) ++N;
    }
}
using namespace Num;


i64 I1, I2;
int area, N;

void find_area()
{
    cFor (IV, p, primes) {
        int prime = *p;
        if (I1 % prime == 0) {
            area = prime;
            return;
        }
    }
}

void solve()
{
    find_area();
    assert(I1 % area == 0);
    assert(I2 % area == 0);

    i64 P1 = I1 / area;
    i64 P2 = I2 / area;

    assert(area < P1 && P1 < P2);
    assert(P2 - P1 < MAXDIFF);

    prime_seg_sieve(P1, P2, N);
}

int main()
{
    prime_sieve();

    int T;
    scanf("%d", &T);
    assert(1 <= T && T <= MAXT);

    int ncase = 0;
    while (T--) {
        scanf("%lld%lld", &I1, &I2);
        assert(0 < I1 && I1 < I2 && I2 < MAXI);

        solve();

        printf("Case %d: area %d has %d crates\n", ++ncase, area, N);
    }

    return 0;
}
