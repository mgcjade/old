#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int a[505];
int f[250005];
bool bz[250005];
int mn = INF, mx;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(f, 0x3f, sizeof(f));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }
    for (int i = 1; i <= n; i++)
        a[i] -= mn;
    mx = (mx - mn) * k;
    // cout << mx << '\n';
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i]; j <= mx; j++)
        {
            f[j] = min(f[j - a[i]] + 1, f[j]);
            // cout << i << ' ' << j << ' ' << f[j] << '\n';
        }
    for (int j = 0; j <= mx; j++)
        if (f[j] <= k)
        {
            bz[j + k * mn] = 1;
            // cout << j + k * mn << '\n';
        }
    mx += mn * k;
    for (int i = 1; i <= mx; i++)
        if (bz[i])
            cout << i << ' ';
    return 0;
}