#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int fa[N];
int c[N];
int dp[N][2];
int ans;
int root[N], cnt;
int vis[N];

vector<int> e[N];

void dfs(int u)
{
    for (auto v : e[u])
    {
        dp[v][0] = 0, dp[v][1] = c[v];
        dfs(v);
        dp[u][0] += dp[v][1], dp[u][1] += min(dp[v][0], dp[v][1]);
    }
    // cerr << u << ' ' << dp[u][0] << ' ' << dp[u][1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> fa[i];
        if (fa[i] != i)
            e[fa[i]].push_back(i);
    }
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n)
    {
        if (!vis[i])
        {
            int x = i;
            while (!vis[x])
            {
                vis[x] = i;
                x = fa[x];
            }
            if (vis[x] == i)
                root[++cnt] = x;
        }
    }
    // rep(i, 1, cnt) cerr << root[i] << ' ';
    // cerr << '\n';
    rep(i, 1, cnt)
    {
        int u = root[i];
        if (fa[u] == u)
        {
            dfs(u);
            ans += dp[u][1];
            continue;
        }
        int tmp = fa[u];
        e[tmp].erase(find(e[tmp].begin(), e[tmp].end(), u)), fa[u] = i;
        dp[u][0] = 0, dp[u][1] = c[u];
        dfs(u);
        int _ans = dp[u][1];
        e[tmp].push_back(u), fa[u] = tmp;

        u = fa[u];
        tmp = fa[u];
        e[tmp].erase(find(e[tmp].begin(), e[tmp].end(), u)), fa[u] = i;
        dp[u][0] = 0, dp[u][1] = c[u];
        dfs(u);
        _ans = min(_ans, dp[u][1]);
        e[tmp].push_back(u), fa[u] = tmp;

        ans += _ans;
    }
    cout << ans << '\n';
    return 0;
}