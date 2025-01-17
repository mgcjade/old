#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 505;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int k;
string str, s;
int len, n;
int dp[N][N];
int sum[N];

void solve(int st)
{
    memset(dp, 0x3f, sizeof(dp));
    rep(i, st - 1, n) dp[i][0] = i - st + 1;
    rep(i, 0, n) dp[st - 1][i] = i;
    rep(i, st, n) rep(j, 1, len)
    {
        if (s[i - 1] == str[j - 1])
            dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        else
            dp[i][j] = min(dp[i][j], min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1));
        // cout << st << ' ' << i << ' ' << j << ' ' << dp[i][j] << '\n';
    }
    rep(i, st, n) if (dp[i][len] <= k) sum[dp[i][len]]++;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> k;
    cin >> str;
    len = str.size();
    cin >> s;
    n = s.size();
    rep(st, 1, n)
    {
        solve(st);
    }
    rep(i, 0, k) cout << sum[i] << '\n';
    return 0;
}