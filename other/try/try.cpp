#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int main()
{
    fre(10);
    int N;
    cin >> N;
    int a[N + 5] = {0};
    int i, n, j = 1;
    for (i = 1; i <= N; i++)
    {
        n = 1;
        do
        {
            if (j > N)
                j = 1;
            if (a[j])
                j++;
            else
            {
                if (n == i)
                    a[j] = i;
                j++;
                n++;
            }
        } while (n <= i);
    }
    for (i = 1; i <= N; i++)
        printf("%d ", a[i]);
    printf("\n");
}
