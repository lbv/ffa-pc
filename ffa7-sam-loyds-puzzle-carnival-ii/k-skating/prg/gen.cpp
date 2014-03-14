#include <cstdio>
#include <cstdlib>
#include <ctime>

#define MAXT 5000
#define MAXRI 1000
#define MAXTI 3000


int T;


void print_case(int ir, int it)
{
    double r = ir;
    double t = it;
    printf("%.2lf %.2lf\n", r / 100.0, t / 100.0);
    --T;
}

void test_case()
{
    int r = rand() % (MAXRI - 100) + 101;
    int t = rand() % MAXTI + 1;
    print_case(r, t);
}

int main()
{
    srand(time(NULL));

    T = MAXT;
    printf("%d\n", T);

    for (int i = 0; i < 10; ++i) {
        print_case(101 + i, 1 + i);
        print_case(1000 - i, 3000 - i);
        print_case(101 + i, 3000 - i);
        print_case(1000 - i, 1 + 1);
    }

    while (T) test_case();

    return 0;
}
