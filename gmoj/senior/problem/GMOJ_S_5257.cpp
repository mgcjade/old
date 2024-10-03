#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, T;
int x, y, z;
int to[N], nxt[N], hd[N], tot;
void add_edge(int u, int v)
{
    ++tot;
    to[tot] = v;
    nxt[tot] = hd[u];
    hd[u] = tot;
}
int s;
int dep[N], fa[N][30];
void made(int k, int f)
{
    fa[k][0] = f;
    dep[k] = dep[f] + 1;
    for (int i = 1; i <= s; i++)
        fa[k][i] = fa[fa[k][i - 1]][i - 1];
    for (int i = hd[k]; i; i = nxt[i])
    {
        int v = to[i];
        if (v != f)
            made(v, k);
    }
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    for (int i = s; i >= 0; i--)
        if (dep[fa[u][i]] >= dep[v])
            u = fa[u][i];
    if (u == v)
        return u;
    for (int i = s; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T >> z;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    s = __lg(n);
    made(1, 0);
    int mid, t;
    int ans;
    while (T--)
    {
        cin >> x >> y >> z;
        mid = lca(x, y);
        t = lca(y, z);
        if (dep[t] > dep[mid])
            mid = t;
        t = lca(x, z);
        if (dep[t] > dep[mid])
            mid = t;
        t = lca(y, mid);
        ans = dep[mid] - dep[t] + dep[y] - dep[t] + 1;
        cout << ans << '\n';
    }
    return 0;
}