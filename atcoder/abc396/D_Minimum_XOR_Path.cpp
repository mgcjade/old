#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
vector<pair<int, int>> e[12];
int ans = INF;

int vis[12];
void dfs(int u, int sum)
{
    if (u == n)
    {
        ans = min(ans, sum);
        return;
    }
    vis[u] = 1;
    for (auto [v, w] : e[u])
        if (!vis[v])
            dfs(v, sum ^ w);
    vis[u] = 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << ans;
    return 0;
}