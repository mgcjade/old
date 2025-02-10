#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
#define int long long

const int N = 2e6 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline int lowbit(int x) { return x & (-x); }

int n;
int ans;
vector<int> e[N];
vector<int> t1[N], t2[N];
int pre[N], siz[N], dfn[N], tre[N];
int cnt;

int fnd(int x) { return pre[x] = (x == pre[x] ? x : fnd(pre[x])); }

void upd(int x, int val)
{
    while (x <= n)
        tre[x] += val, x += lowbit(x);
}
int qry(int x)
{
    int res = 0;
    while (x)
        res += tre[x], x -= lowbit(x);
    return res;
}

void dfs1(int u, int fa)
{
    siz[u] = 1, dfn[u] = ++cnt;
    for (auto v : t1[u])
    {
        if (v == fa)
            continue;
        dfs1(v, u);
        siz[u] += siz[v];
    }
}
void dfs2(int u, int fa)
{
    upd(dfn[u], 1);
    for (auto v : t2[u])
    {
        if (v == fa)
            continue;
        dfs2(v, u);
    }
    ans += qry(dfn[u] + siz[u] - 1) - qry(dfn[u] - 1) - 1;
    upd(dfn[u], -1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        int v;
        cin >> v;
        if (v)
            e[i].push_back(v), e[v].push_back(i);
        pre[i] = i;
    }
    rep(i, 1, n) for (auto v : e[i]) if (v < i)
    {
        int nx = fnd(v), ny = fnd(i);
        pre[nx] = ny, t2[nx].push_back(ny), t2[ny].push_back(nx);
    }
    rep(i, 1, n) pre[i] = i;
    reb(i, n, 1) for (auto v : e[i]) if (v > i)
    {
        int nx = fnd(v), ny = fnd(i);
        pre[nx] = ny, t1[nx].push_back(ny), t1[ny].push_back(nx);
    }
    dfs1(1, 0);
    dfs2(n, 0);
    cout << ans << '\n';
    return 0;
}