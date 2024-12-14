#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 50;
int t, n, a[N * 2];
int sum = 0;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[n + i] = a[i];
        sum += a[i];
    }
    t %= sum, n <<= 1;
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = n, mid;
        while (l <= r)
        {
            mid = (l + r) >> 1;
            if (a[mid] == a[i] - t)
            {
                cout << "Yes";
                return 0;
            }
            if (a[mid] < a[i] - t)
                l = mid + 1;
            else
                r = mid - 1;
        }
    }
    cout << "No";
}