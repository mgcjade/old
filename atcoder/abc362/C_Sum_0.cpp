#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int l[N], r[N];
int sum1, sum2;
int ans[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> l[i] >> r[i];
        sum1 += l[i];
        sum2 += r[i];
    }
    if (sum1 > 0 || sum2 < 0)
    {
        cout << "No\n";
        return 0;
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] > 0)
            sum += l[i], ans[i] = l[i];
        else if (r[i] < 0)
            sum += r[i], ans[i] = r[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i] == 0)
        {
            if (sum < 0)
            {
                ans[i] = min(-sum, r[i]);
                sum += ans[i];
            }
            else
            {
                ans[i] = max(-sum, l[i]);
                sum += ans[i];
            }
        }
    }
    if (sum != 0)
    {
        cout << "No\n";
        return 0;
    }
    cout << "Yes" << '\n';
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}