#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 5005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, C;
int w[N], v[N], c[N];
int sum[N], lim[N];
int f[N][N];
int dp[2][N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> C;
    rep(i, 1, n) cin >> v[i] >> w[i] >> c[i], sum[c[i]] += w[i];
    rep(i, 1, C) cin >> lim[i], lim[i] = min(lim[i], sum[i]);
    rep(i, 1, C)
    {
        rep(k, 1, n) if (c[k] == i) reb(j, lim[i], w[k]) f[i][j] = max(f[i][j], f[i][j - w[k]] + v[k]);
        // rep(j, 1, lim[i]) cout << f[i][j] << ' ';
        // cout << '\n';
    }
    rep(i, 1, C)
    {
        rep(k, 0, m) dp[i & 1][k] = dp[i & 1 ^ 1][k];
        rep(j, 1, lim[i]) reb(k, m, j) dp[i & 1][k] = max(dp[i & 1][k], dp[(i & 1) ^ 1][k - j] + f[i][j]);
        // rep(k, 1, m) cout << dp[i][k] << ' ';
        // cout << '\n';
    }
    cout << dp[C & 1][m] << '\n';
    return 0;
}