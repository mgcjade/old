#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int to[N], nxt[N], hd[N], tot;
void add(int u, int v)
{
    ++tot;
    to[tot] = v;
    nxt[tot] = hd[u];
    hd[u] = tot;
}

int f[N], dep[N];
void made(int u, int fa)
{
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != fa)
            made(v, u);
    }
}
int vis[N];
void dfs(int u)
{
    int nx = 0;
    if (vis[u] == 0)
        k--;
    vis[u] = 1;
    cout << u << ' ';
    for (int i = hd[u]; i; i = nxt[i])
    {
        int v = to[i];
        if (vis[v] == 0 && k > 0)
        {
            dfs(v);
            cout << u << ' ';
        }
        if (vis[v] == 2)
            nx = v;
    }
    if (nx > 0)
        dfs(nx);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;

        for (int i = 1; i <= n; i++)
            hd[i] = 0, vis[i] = 0;
        tot = 0;

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            add(u, v);
            add(v, u);
        }
        made(1, 0);
        int ans, mx = 0;
        for (int i = 1; i <= n; i++)
            if (dep[i] > dep[mx] && dep[i] <= k)
                mx = i;
        ans = 2 * (k - 1) - (dep[mx] - 2);
        cout << ans << '\n';
        k -= dep[mx];
        for (int i = mx; i; i = f[i])
            vis[i] = 2;
        dfs(1);
        cout << '\n';
    }
    return 0;
}