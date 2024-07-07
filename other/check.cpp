#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
bool vis[1500];
vector<int> edge[1500];
bool e[1500][1500];

void dfs(int u)
{
    vis[u] = 1;
    for (int v : edge[u])
        if (!vis[v] && !e[u][v])
            dfs(v);
}
int u[1500], v[1500];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> u[i] >> v[i];
        edge[u[i]].push_back(v[i]);
        edge[v[i]].push_back(u[i]);
    }
    for (int i = 1; i < m; i++)
    {
        memset(vis, 0, sizeof(vis));
        e[u[i]][v[i]] = e[v[i]][u[i]] = 1;
        dfs(u[i]);
        e[u[i]][v[i]] = e[v[i]][u[i]] = 0;
        for (int i = 1; i <= n; i++)
            if (!vis[i])
            {
                cout << -1 << '\n';
                return 0;
            }
    }
    cout << 1 << '\n';
    return 0;
}