#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int h[3005];
int dp[3005][3005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> h[i];
    }
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            dp[i][j] = 1;
        }
    }
    rep(i, 1, n)
    {
        reb(j, i - 1, 1)
        {
            if (h[j] == h[i])
                dp[i][i - j] = max(dp[i][i - j], dp[j][i - j] + 1);
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        rep(j, 1, n)
        {
            ans = max(ans, dp[i][j]);
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }
    cout << ans << endl;
    return 0;
}