#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

map<int, int> mp;
int table[N], _tot;

struct segment_tree
{
    int l, r;
    int num_mx, mx;
    int lson, rson;
};
segment_tree t[N * 40];
int root[N], tot;
void pushup(int k)
{
    if (t[t[k].lson].mx > t[t[k].rson].mx)
        t[k].num_mx = t[t[k].lson].num_mx;
    else if (t[t[k].lson].mx < t[t[k].rson].mx)
        t[k].num_mx = t[t[k].rson].num_mx;
    else
        t[k].num_mx = min(t[t[k].lson].num_mx, t[t[k].rson].num_mx);
    t[k].mx = max(t[t[k].lson].mx, t[t[k].rson].mx);
}
void add(int k, int u, int v)
{
    if (t[k].l == t[k].r)
    {
        if (t[k].l == u)
        {
            t[k].mx += v;
            t[k].num_mx = table[u];
        }
        return;
    }
    int mid = (t[k].l + t[k].r) >> 1;
    if (u <= mid)
    {
        if (t[k].lson == 0)
        {
            ++tot;
            t[k].lson = tot;
            t[tot].l = t[k].l, t[tot].r = mid;
        }
        add(t[k].lson, u, v);
    }
    else
    {
        if (t[k].rson == 0)
        {
            ++tot;
            t[k].rson = tot;
            t[tot].l = mid + 1, t[tot].r = t[k].r;
        }
        add(t[k].rson, u, v);
    }
    pushup(k);
}
int merge(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (t[a].l == t[a].r)
    {
        t[a].mx += t[b].mx;
        return a;
    }
    t[a].lson = merge(t[a].lson, t[b].lson);
    t[a].rson = merge(t[a].rson, t[b].rson);
    pushup(a);
    return a;
}
void update(int k)
{
    if (t[k].l == t[k].r)
        return;
    if (t[k].lson)
        update(t[k].lson);
    if (t[k].rson)
        update(t[k].rson);
    pushup(k);
}

int n;
struct edge
{
    int to;
    int nxt;
};
edge e[N << 1];
int hd[N], cnt;
void add_edge(int u, int v)
{
    ++cnt;
    e[cnt].to = v;
    e[cnt].nxt = hd[u];
    hd[u] = cnt;
}
int fa[N][25], dep[N];
void made(int k)
{
    dep[k] = dep[fa[k][0]] + 1;
    for (int i = hd[k]; i; i = e[i].nxt)
    {
        if (e[i].to != fa[k][0])
        {
            fa[e[i].to][0] = k;
            made(e[i].to);
        }
    }
}

int m;
int x, y, z;

int ans[N];
void dfs(int k)
{
    for (int i = hd[k]; i; i = e[i].nxt)
    {
        if (e[i].to != fa[k][0])
        {
            dfs(e[i].to);
            root[k] = merge(root[k], root[e[i].to]);
        }
    }
    // update(root[k]);
    ans[k] = t[root[k]].num_mx * (t[root[k]].mx > 0);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }

    made(1);
    int s = __lg(n);
    for (int j = 1; j <= s; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];

    for (int i = 1; i <= n; i++)
    {
        root[i] = i;
        t[root[i]].l = 1, t[root[i]].r = n;
    }
    tot = n;

    while (m--)
    {
        cin >> x >> y >> z;
        if (mp[z] == 0)
        {
            _tot++;
            mp[z] = _tot;
            table[_tot] = z;
        }
        add(root[x], mp[z], 1);
        add(root[y], mp[z], 1);
        int fx = x, fy = y;
        if (dep[fx] < dep[fy])
            swap(fx, fy);
        for (int i = s; i >= 0; i--)
            if (dep[fa[fx][i]] >= dep[fy])
                fx = fa[fx][i];
        for (int i = s; i >= 0; i--)
            if (fa[fx][i] != fa[fy][i])
                fx = fa[fx][i], fy = fa[fy][i];
        if (fx != fy)
            fx = fa[fx][0], fy = fa[fy][0];
        add(root[fx], mp[z], -1);
        add(root[fa[fx][0]], mp[z], -1);
        // cout << x << ' ' << y << ' ' << fx << ' ' << fy << ' ' << z << '\n';
    }

    // for (int i = 0; i <= tot; i++)
    //     cout << i << ' ' << t[i].l << ' ' << t[i].r << ' ' << t[i].mx << ' ' << t[i].num_mx << ' ' << t[i].lson << ' ' << t[i].rson << '\n';

    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';

    // for (int i = 0; i <= tot; i++)
    //     cout << i << ' ' << t[i].l << ' ' << t[i].r << ' ' << t[i].mx << ' ' << t[i].num_mx << ' ' << t[i].lson << ' ' << t[i].rson << '\n';

    return 0;
}