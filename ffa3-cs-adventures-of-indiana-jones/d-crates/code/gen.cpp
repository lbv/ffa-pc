#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

#define MAXT 80
#define MAXI 1000000000000LL
#define MAXDIFF 1000000

#define cFor(t,v,c)  for(t::const_iterator v=c.begin(); v != c.end(); ++v)

typedef long long          i64;
typedef unsigned long long u64;

typedef vector<int>  IV;
typedef vector<i64>  I64V;
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
    void prime_seg_sieve(i64 a, i64 b, I64V &seg_primes) {
        BV pmap(b - a + 1, true);
        i64 sqr_b = sqrt(b);
        cFor (IV, pp, primes) {
            int p = *pp;
            if (p > sqr_b) break;
            for (i64 j = (a+p-1)/p, v=(j==1?p+p:j*p); v <= b; v += p)
                pmap[v-a] = false;
        }
        if (a == 1) pmap[0] = false;
        seg_primes.clear();
        for (int i = a%2 ? 0 : 1, I = b - a + 1; i < I; i += 2)
            if (pmap[i]) seg_primes.push_back(a + i);
    }
}
using namespace Num;

int NP;  // number of primes < 10^6

u64 rand_u64()
{
    u64 r = rand();
    r <<= 32;
    r |= rand();
    return r;

}

void test_case()
{
    i64 PA;
    if (rand() % 5 == 0)
        PA = primes[rand() % 10];
    else
        PA = primes[rand() % (NP - 2)];

    i64 L1, L2;

    L2 = MAXI / PA;
    L2 = rand_u64() % (L2 - PA) + PA + 1;
    L1 = max(PA + 1, L2 - MAXDIFF);

    fprintf(stderr, "PA(%lld) L1(%lld) L2(%lld)\n", PA, L1, L2);

    I64V ps;
    prime_seg_sieve(L1, L2, ps);

    i64 P1, P2;
    do {
        int a = rand() % ps.size();
        int b = rand() % ps.size();
        P1 = ps[min(a, b)];
        P2 = ps[max(a, b)];
    } while(P1 == P2);

    printf("%lld %lld\n", PA * P1, PA * P2);
}

int main()
{
    srand(time(NULL));

    prime_sieve();
    NP = primes.size();

    int T = MAXT;
    printf("%d\n", T);

    printf("6 10\n"); --T;
    printf("187 253\n"); --T;
    printf("9906573 9906753\n"); --T;
    printf("999940000819 999944000663\n"); --T;

    while (T--) test_case();

    return 0;
}
