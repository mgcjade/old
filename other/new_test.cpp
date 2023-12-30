#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int main()
{
    freopen("new_test.in", "w", stdout);
    int n = 1e5;
    const int MAX = 1e6 + 1;
    printf("%d\n", n);
    int t;
    for (int i = 1; i <= n; i++)
    {
        srand(time(0) * t + rand());
        t = rand();
        srand(t);
        t = rand() % (int)1e5;
        srand(t * t);
        t = rand();
        srand(time(0) * t + rand());
        t = rand() % MAX;
        printf("%d ", t);
    }
    return 0;
}