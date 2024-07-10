#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;

int n, m, r, MOD;
int a[N];
struct Segment_tree
{
    int sum;
    int lz;
    int l, r;
};
Segment_tree t[N << 2];
void pushup(int k)
{
    t[k].sum = (t[k << 1].sum + t[k << 1 ^ 1].sum) % MOD;
}
void pushdown(int k)
{
    t[k << 1].lz = (t[k << 1].lz + t[k].lz) % MOD;
    t[k << 1 ^ 1].lz = (t[k << 1 ^ 1].lz + t[k].lz) % MOD;
    t[k << 1].sum = (t[k << 1].sum + t[k].lz * (t[k << 1].r - t[k << 1].l + 1)) % MOD;
    t[k << 1 ^ 1].sum = (t[k << 1 ^ 1].sum + t[k].lz * (t[k << 1 ^ 1].r - t[k << 1 ^ 1].l + 1)) % MOD;
    t[k].lz = 0;
}
void made(int k, int l, int r)
{
    t[k].l = l;
    t[k].r = r;
    t[k].sum = 0;
    t[k].lz = 0;
    if (l == r)
    {
        t[k].sum = a[l];
        // cout << k << " " << l << " " << r << ' ' << t[k].sum << '\n';
        return;
    }
    int mid = (l + r) >> 1;
    made(k << 1, l, mid);
    made(k << 1 ^ 1, mid + 1, r);
    pushup(k);
    // cout << k << " " << l << " " << r << ' ' << t[k].sum << '\n';
}
void update(int k, int l, int r, int val)
{
    if (t[k].r < l || r < t[k].l)
        return;
    if (l <= t[k].l && t[k].r <= r)
    {
        t[k].lz = (t[k].lz + val) % MOD;
        t[k].sum = (t[k].sum + val * (t[k].r - t[k].l + 1)) % MOD;
        return;
    }
    pushdown(k);
    update(k << 1, l, r, val);
    update(k << 1 ^ 1, l, r, val);
    pushup(k);
}
int query(int k, int l, int r)
{
    if (t[k].r < l || r < t[k].l)
        return 0;
    if (l <= t[k].l && t[k].r <= r)
        return t[k].sum;
    pushdown(k);
    int mid = (t[k].l + t[k].r) >> 1;
    return (query(k << 1, l, r) + query(k << 1 ^ 1, l, r)) % MOD;
}

vector<int> e[N];
struct tree
{
    int val, dep;
    int fa, dfn;
    int sz, hson, hd;
};
tree tr[N];
int rnk[N], tot;
bool vis[N];
void dfs1(int k)
{
    vis[k] = true;
    tr[k].sz = 1;
    tr[k].dep = tr[tr[k].fa].dep + 1;
    int mx = 0;
    for (int i = 0; i < e[k].size(); i++)
    {
        if (!vis[e[k][i]])
        {
            tr[e[k][i]].fa = k;
            dfs1(e[k][i]);
            if (tr[e[k][i]].sz > tr[mx].sz)
                mx = e[k][i];
            tr[k].sz += tr[e[k][i]].sz;
        }
    }
    tr[k].hson = mx;
}
void dfs2(int k, int hd)
{
    tot++;
    a[tot] = tr[k].val;
    rnk[tot] = k;
    tr[k].dfn = tot;
    vis[k] = false;
    tr[k].hd = hd;
    if (tr[k].hson)
    {
        dfs2(tr[k].hson, hd);
    }
    for (int i = 0; i < e[k].size(); i++)
    {
        if (vis[e[k][i]] && e[k][i] != tr[k].hson)
            dfs2(e[k][i], e[k][i]);
    }
}
void init()
{
    tr[r].fa = r;
    dfs1(r);
    dfs2(r, r);
    made(1, 1, n);
    // for (int i = 1; i <= n; i++)
    //     cout << tr[i].dep << " " << tr[i].dfn << " " << tr[i].fa << " " << tr[i].hson << " " << tr[i].sz << " " << tr[i].val << ' ' << tr[i].hd << "\n";
}

void update1(int x, int y, int val)
{
    while (tr[x].hd != tr[y].hd)
    {
        if (tr[tr[x].hd].dep < tr[tr[y].hd].dep)
            swap(x, y);
        update(1, tr[tr[x].hd].dfn, tr[x].dfn, val);
        x = tr[tr[x].hd].fa;
    }
    if (tr[x].dfn > tr[y].dfn)
        swap(x, y);
    update(1, tr[x].dfn, tr[y].dfn, val);
}
int query2(int x, int y)
{
    int res = 0;
    while (tr[x].hd != tr[y].hd)
    {
        if (tr[tr[x].hd].dep < tr[tr[y].hd].dep)
            swap(x, y);
        res = (res + query(1, tr[tr[x].hd].dfn, tr[x].dfn)) % MOD;
        x = tr[tr[x].hd].fa;
    }
    if (tr[x].dfn > tr[y].dfn)
        swap(x, y);
    res = (res + query(1, tr[x].dfn, tr[y].dfn)) % MOD;
    return res;
}
void update3(int x, int val)
{
    update(1, tr[x].dfn, tr[x].dfn + tr[x].sz - 1, val);
}
int query4(int x)
{
    return query(1, tr[x].dfn, tr[x].dfn + tr[x].sz - 1) % MOD;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> MOD;
    for (int i = 1; i <= n; i++)
        cin >> tr[i].val;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    init();
    int flag;
    int x, y, z;
    while (m--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> x >> y >> z;
            update1(x, y, z);
        }
        else if (flag == 2)
        {
            cin >> x >> y;
            cout << query2(x, y) << "\n";
        }
        else if (flag == 3)
        {
            cin >> x >> z;
            update3(x, z);
        }
        else if (flag == 4)
        {
            cin >> x;
            cout << query4(x) << "\n";
        }
    }
    // for (int i = 1; i <= 9; i++)
    //     cout << t[i].l << ' ' << t[i].r << ' ' << t[i].sum << ' ' << t[i].lz << '\n';
    return 0;
}