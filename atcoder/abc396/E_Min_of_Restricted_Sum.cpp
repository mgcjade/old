#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N];
int vis[N];
vector<pair<int, int>> e[N];
vector<pair<int, int>> ans[N];
int cnt;

void mini(vector<pair<int, int>> &A)
{
    int sum = A.size();
    int tp[35];
    memset(tp, 0, sizeof(tp));
    for (auto [x, y] : A)
    {
        for (int i = x; i; i -= (i & -i))
            tp[__lg(i & -i)]++;
    }
    int res = 0, _Tp = sum / 2;
    rep(i, 0, 30) if (tp[i] > _Tp) res |= (1 << i);
    for (auto [x, y] : A)
        a[y] ^= res;
}

void dfs(int u)
{
    vis[u] = 1;
    for (auto [v, w] : e[u])
    {
        if (!vis[v])
        {
            a[v] = (a[u] ^ w);
            ans[cnt].push_back({a[v], v});
            dfs(v);
        }
        else if (a[v] != (a[u] ^ w))
        {
            cout << "-1";
            exit(0);
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    rep(i, 1, n)
    {
        if (!vis[i])
        {
            a[i] = 0;
            ++cnt, ans[cnt].push_back({0, i});
            dfs(i);
        }
    }
    rep(i, 1, cnt)
    {
        mini(ans[i]);
    }
    rep(i, 1, n) cout << a[i] << ' ';
    // cout << -1;
    return 0;
}