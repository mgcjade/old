#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int w[N], fa[N];

vector<int> e[N];
map<int, int> mp[N];

void built(int u, int f)
{
    fa[u] = f;
    for (auto v : e[u])
    {
        if (v == f)
            continue;
        built(v, u);
        mp[u][w[v]] = v;
    }
}
int query(int u, int x)
{
    auto it = mp[u].lower_bound(x);
    if (it == mp[u].end())
        return u;
    return query(it->second, x);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> n >> T;
    rep(i, 1, n) cin >> w[i];
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    built(1, 0);
    while (T--)
    {
        int op;
        int x, y;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            mp[fa[x]][y] = x;
            mp[fa[x]].erase(w[x]);
            w[x] = y;
        }
        else
        {
            cin >> x;
            cout << query(1, x) << '\n';
        }
    }
    return 0;
}