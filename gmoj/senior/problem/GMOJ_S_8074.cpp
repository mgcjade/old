#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int sz[N], dep[N];
int sum;
int f[N][25];
int s;
int v[N][25];
int ans = INF;

struct edge
{
    int to, nxt;
};
edge e[N << 1];
int hd[N], cnt;
void add_edge(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].nxt = hd[x];
    hd[x] = cnt;
}

void dfs(int k, int fa)
{
    dep[k] = dep[fa] + 1;
    sz[k] = 1;
    for (int i = hd[k]; i; i = e[i].nxt)
        if (e[i].to != fa)
        {
            dfs(e[i].to, k);
            sz[k] += sz[e[i].to];
        }
}
void dfs1(int k, int fa)
{
    int mx = -1, w = k, t;
    int nw = sum;
    for (int i = hd[k]; i; i = e[i].nxt)
        if (e[i].to != fa)
        {
            dfs1(e[i].to, k);
            t = (dep[e[i].to] - 1) * sz[e[i].to];
            if (t > mx)
            {
                mx = t;
                w = e[i].to;
            }
        }
    nw -= mx;
    t = w;
    for (int i = s; i >= 0; i--)
    {
        if (f[w][i] && dep[t] + 1 < 2 * dep[f[w][i]])
        {
            nw -= v[w][i] - (dep[t] - dep[w]) * (sz[f[w][i]] - sz[w]);
            w = f[w][i];
        }
    }
    ans = min(ans, nw);
}
void dfs2(int k, int fa)
{
    f[k][0] = fa;
    v[k][0] = (2 * dep[fa] - dep[k] - 1) * (sz[fa] - sz[k]);
    for (int j = 1; j <= s; j++)
    {
        f[k][j] = f[f[k][j - 1]][j - 1];
        if (f[k][j])
            v[k][j] = v[k][j - 1] + v[f[k][j - 1]][j - 1] - (dep[k] - dep[f[k][j - 1]]) * (sz[f[k][j]] - sz[f[k][j - 1]]);
    }
    for (int i = hd[k]; i; i = e[i].nxt)
        if (e[i].to != fa)
            dfs2(e[i].to, k);
}

signed main()
{
    // fre(road);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    s = __lg(n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    dep[0] = -1;
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        sum += dep[i];
    dfs2(1, 0);
    ans = sum;
    dfs1(1, 0);
    cout << ans;
    return 0;
}