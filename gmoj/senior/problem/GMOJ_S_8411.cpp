#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 300;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
struct node
{
    int x, y, z;
} a[N], b[N];
int ans;
int vis[N];
int flag[N];

int dp[N][N][N];
pair<int, int> x[N], y[N], z[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i].x >> a[i].y >> a[i].z;
    rep(i, 1, n)
    {
        x[i] = {a[i].x, i};
        y[i] = {a[i].y, i};
        z[i] = {a[i].z, i};
    }
    // 离散化
    sort(x + 1, x + n + 1);
    sort(y + 1, y + n + 1);
    sort(z + 1, z + n + 1);
    rep(i, 1, n)
    {
        b[x[i].second].x = i;
        b[y[i].second].y = i;
        b[z[i].second].z = i;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[1][1][1] = 0;
    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n)
    {
        auto xx = x[i].second, yy = y[j].second, zz = z[k].second;
        if (b[xx].y <= j && b[xx].z <= k)
            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + (y[j].first - a[xx].y) + (z[k].first - a[xx].z));
        if (b[yy].x <= i && b[yy].z <= k)
            dp[i][j][k] = min(dp[i][j][k], dp[i][j - 1][k] + (x[i].first - a[yy].x) + (z[k].first - a[yy].z));
        if (b[zz].x <= i && b[zz].y <= j)
            dp[i][j][k] = min(dp[i][j][k], dp[i][j][k - 1] + (x[i].first - a[zz].x) + (y[j].first - a[zz].y));
    }

    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) cout << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << '\n';

    cout << dp[n][n][n] << '\n';

    return 0;
}