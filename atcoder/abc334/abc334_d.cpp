#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int n, q;
ll a[200005];
ll t;

int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    while (q--)
    {
        scanf("%lld", &t);
        int h = 1, r = n;
        while (h <= r)
        {
            int mid = (h + r) >> 1;
            if (a[mid] <= t)
                h = mid + 1;
            else
                r = mid - 1;
        }
        printf("%d\n", h - 1);
    }
    return 0;
}