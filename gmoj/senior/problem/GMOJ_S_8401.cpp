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

int n, m;
vector<pair<int, int>> edge[N];
void add_edge(int u, int v, int w)
{
    edge[u].push_back({v, w});
}
int dis[N];
vector<int> e[N];

ll f[N], g[N], h[N];

void dijkstra(int s)
{
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty())
    {
        auto [d, u] = q.top();
        q.pop();
        if (d != dis[u])
            continue;
        for (auto [v, w] : edge[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    // rep(i, 1, n) cout << dis[i] << " ";
}

int rd[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        add_edge(u, v, w);
    }
    dijkstra(1);
    rep(i, 1, n)
    {
        for (auto [v, w] : edge[i])
            if (dis[v] == dis[i] + w)
                e[i].push_back(v), rd[v]++;
    }
    queue<int> q;
    q.push(1);
    f[1] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : e[u])
        {
            f[v] += f[u];
            g[v] += g[u] + f[u];
            h[v] += h[u] + 2 * g[u] + f[u];
            f[v] %= MOD, g[v] %= MOD, h[v] %= MOD;
            --rd[v];
            if (rd[v] == 0)
                q.push(v);
        }
    }
    // rep(i, 1, n) cout << f[i] << ' ' << g[i] << ' ' << h[i] << '\n';
    ll ans = 0;
    rep(i, 1, n) ans = (ans += (g[i] * g[i] - h[i]) / 2) % MOD /*, cout << ans << ' '*/;
    cout << ans << '\n';
    // rep(i, 1, n) for (auto j : e[i]) cout << i << ' ' << j << '\n';
    return 0;
}