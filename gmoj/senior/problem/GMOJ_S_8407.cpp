#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
int a[N + 5];
int dp[N + 5];

void solve()
{
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    rep(i, 1, n)
    {
        int mx = a[i];
        reb(j, i, 0)
        {
            mx = max(mx, a[j]);
            if (i - j + 1 >= mx)
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        int t = a[i];
        a[i] = 1;
        solve();
        a[i] = t;
        cout << dp[n] << " ";
        // rep(i, 1, n) cout << dp[i] << " ";
        // cout << "\n";
    }
    return 0;
}