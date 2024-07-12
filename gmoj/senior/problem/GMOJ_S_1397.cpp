#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k, a[N], dp[N][N][2], f[N][11], sum, ans = 1 << 30;
int Max(int L, int R)
{
    int lg = (int)log2(R - L + 1);
    return max(f[L][lg], f[R - (1 << lg) + 1][lg]);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dp, 0x3f, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    int s = n - 2 * k;
    for (int i = 1; i < s; i++)
        a[i] = a[i + k + 1];

    n = s - 1;
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    for (int j = 1; j <= 10; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);

    dp[1][n][0] = 0, dp[1][n][1] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = n; j >= i; j--)
        {
            int mx = Max(i, j);
            dp[i + 1][j][0] = min(dp[i][j][0] + mx, dp[i + 1][j][0]);
            dp[i + 1][j][0] = min(dp[i][j][1] + mx * (n - j + i), dp[i + 1][j][0]);
            dp[i][j - 1][1] = min(dp[i][j][1] + mx, dp[i][j - 1][1]);
            dp[i][j - 1][1] = min(dp[i][j][0] + mx * (n - j + i), dp[i][j - 1][1]);
        }
    for (int i = 1; i <= n; i++)
        ans = min(ans, min(dp[i][i][0], dp[i][i][1]) + a[i]);
    printf("%d", ans + sum);
    return 0;
}