#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int f[N][N << 1], dp[N][N << 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i + n] = a[i];
    for (int l = 3; l <= n; l++)
        for (int i = 1, j = l; j <= 2 * n; i++, j++)
        {
            dp[i][j] = INF;
            for (int k = i + 1; k < j; k++)
            {
                f[i][j] = max(f[i][j], f[i][k] + f[k][j] + a[i] * a[j] * a[k]);
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[j] * a[k]);
            }
        }
    int mx = 0, mn = INF, ans;
    for (int i = 1, j = n; i <= n; i++, j++)
        mx = max(mx, f[i][j]), mn = min(mn, dp[i][j]);
    cout << mx - mn << '\n';
    // for (int l = 3; l <= n; l++)
    //     for (int i = 1, j = l; j <= n * 2; i++, j++)
    //         cout << i << ' ' << j << ' ' << f[i][j] << '\n';
    // for (int i = 1; i <= n * 2; i++)
    //     cout << a[i] << ' ';
    return 0;
}