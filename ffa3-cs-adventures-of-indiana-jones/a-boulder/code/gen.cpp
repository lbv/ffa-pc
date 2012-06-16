#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 2000

// Constants multiplied by 100, to provide for decimal digits
#define MAXE 100000
#define MAXV 10000
#define MAXA 1000

#define D(v) static_cast<double>(v)

void test_case()
{
    int E = rand() % MAXE;
    int I = rand() % (E + 1);
    int V = rand() % MAXV + 1;
    int A = rand() % MAXA + 1;

    printf("%.2lf %.2lf %.2lf %.2lf\n",
           D(I)/100, D(E)/100, D(V)/100, D(A)/100);
}

int main()
{
    srand(time(NULL));

    int T = MAXT;
    printf("%d\n", T);

    printf("60.00 150.00 6.00 1.31\n"); --T;
    printf("60.00 150.00 6.00 1.50\n"); --T;
    printf("4.00 8.00 1.00 1.00\n"); --T;
    printf("0.00 0.00 1.00 1.00\n"); --T;
    printf("1000.00 1000.00 0.01 10.00\n"); --T;

    while (T--) test_case();

    return 0;
}
