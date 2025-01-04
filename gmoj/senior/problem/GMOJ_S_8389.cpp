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

int n;
int ans;

struct dot
{
    vector<int> edge;
    vector<int> son;
    int fa;
    int dep, size;
};
dot a[N + 5];
bool vis[N + 5];

void dfs(int u, int fa)
{
    a[u].fa = fa;
    a[u].size = 1;
    for (auto v : a[u].edge)
    {
        if (v == fa)
            continue;
        a[v].dep = a[u].dep + 1;
        dfs(v, u);
        a[u].size += a[v].size;
        a[u].son.push_back(v);
    }
    sort(a[u].son.begin(), a[u].son.end(), [](int x, int y)
         { return a[x].size > a[y].size; });
}
void upd(int u, int x)
{
    ans++;
    for (auto v : a[u].son)
        if (!vis[v] && a[u].size > x)
        {
            vis[v] = 1, a[u].size -= a[v].size;
            upd(v, x);
        }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        a[u].edge.push_back(v);
        a[v].edge.push_back(u);
    }
    dfs(1, 0);
    if (((a[n].dep - a[1].dep) & 1) != (n & 1))
        return cout << -1 << '\n', 0;
    vector<int> rd;
    for (int u = n; u; u = a[u].fa)
        vis[u] = 1, rd.push_back(u);
    reverse(rd.begin(), rd.end());
    for (auto i : rd)
        a[a[i].fa].size -= a[i].size;
    for (int u = n; u; u = a[u].fa)
        upd(u, (n + 2 * a[u].dep - a[n].dep) / 2);
    cout << ans << '\n';
    return 0;
}