#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
vector<int> edge[N];
bool vis[N], lnk[N];
int dp[N][2];

void dfs(int u, int fa)
{
    if (lnk[u])
    {
        dp[u][0] = 1;
        dp[u][1] = 0;
        return;
    }
    vis[u] = 1;
    dp[u][0] = 0, dp[u][1] = 1;
    for (auto v : edge[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        dp[u][0] = (dp[u][0] * dp[v][1] % MOD + dp[u][1] * dp[v][0] % MOD + 2 * dp[u][0] * dp[v][0] % MOD) % MOD;
        dp[u][1] = (dp[u][1] * dp[v][1] % MOD + 2 * dp[u][1] * dp[v][0] % MOD) % MOD;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(lnk, 1, sizeof(lnk));
    ref(i, 1, n)
    {
        int t;
        cin >> t;
        lnk[t] = 0;
        memset(vis, 0, sizeof(vis));
        int ans = 1;
        rep(j, 1, n)
        {
            if (!lnk[j] && !vis[j])
            {
                dfs(j, 0);
                ans = ans * dp[j][0] % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}