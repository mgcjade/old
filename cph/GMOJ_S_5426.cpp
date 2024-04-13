#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e7 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int dp[N];
int nxt[N], hd[N];
int fa[N], w[N];
int cnt[N];
int ans;
void dfs(int t)
{
    for (int i = hd[t]; i; i = nxt[i])
    {
        dfs(i);
        cnt[t] += cnt[i];
        for (int j = min(k, cnt[t]); j; j--)
        {
            for (int h = min(j, cnt[i]); h; h--)
            {
                dp[t * (k + 1) + j] = max(dp[t * (k + 1) + j], dp[t * (k + 1) + j - h] + dp[i * (k + 1) + h]);
                // cout << t << " " << j << " " << h << ' ' << dp[t][j] << '\n';
            }
        }
    }
    cnt[t] = max(cnt[t], 1);
    dp[t * (k + 1) + 1] = max(dp[t * (k + 1) + 1], w[t]);
}

int main()
{
    // fre(galo);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    k++;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa[i] >> w[i];
        nxt[i] = hd[fa[i]];
        hd[fa[i]] = i;
    }
    dfs(1);
    for (int i = 1; i <= k; i++)
        ans = max(ans, dp[k + 1 + i]);
    cout << ans << '\n';
    return 0;
}
