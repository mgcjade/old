#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

const int N = 2e5 + 10;
const int INF = 1e18;
const int MOD = 1e9 + 7;

int n, ans;
array<int, 5> f[N], g;
vector<int> e[N];

void dfs(int u, int fat)
{
    f[u][0] = 1;
    for (auto v : e[u])
    {
        if (v == fat)
        {
            continue;
        }
        dfs(v, u);
        g = f[u];
        for (int i = 3; i >= 0; --i)
        {
            for (int j = 0; j <= 3; ++j)
            {
                if (!f[u][i] || !f[v][j])
                {
                    continue;
                }
                if (j == 3)
                {
                    g[i + 1] = max(g[i + 1], f[u][i] + f[v][j]);
                }
                if (j == 0)
                {
                    g[i + 1] = max(g[i + 1], f[u][i] + f[v][j]);
                }
            }
        }
        f[u] = g;
    }
    ans = max(ans, max(f[u][1], f[u][4]));
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1, u, v; i < n; ++i)
    {
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    dfs(1, 0);
    cout << (ans < 5 ? -1 : ans);
}
