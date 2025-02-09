#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

template <class _Tp>
_Tp Pow(_Tp a, _Tp b = MOD - 2, _Tp p = MOD)
{
    _Tp res = 1;
    while (b)
    {
        (b & 1) && (res = (ll)res * a % p);
        a = (ll)a * a % p, b >>= 1;
    }
    return res;
}

int T;

int n;
vector<int> e[N];
int du[N];

int ans[N];
int vis[N], fa[N], l[N];
int a[N];
int dfs(int u, int k)
{
    vis[u] = 1;
    int flag = 1, cnt = 0;
    for (auto v : e[u])
    {
        if (!vis[v])
        {
            fa[v] = u;
            flag &= dfs(v, k);
            if (!flag)
                return 0;
            if (l[v] == 1)
                cnt++;
        }
    }
    if (du[u] == 1)
        l[u] = 1, a[u] = 0;
    else
    {
        if (cnt % k == 0)
            l[u] = 1, a[u] = cnt; // 由儿子指向父亲
        else if ((cnt + 1) % k == 0)
            l[u] = 2, a[u] = cnt + 1; // 由父亲指向儿子
        else
            return 0;
    }
    return 1;
}
int check(int k)
{
    rep(i, 1, n) l[i] = 0, vis[i] = 0, a[i] = 0;
    if (!dfs(1, k))
        return 0;
    int g = a[1];
    rep(i, 2, n) g = __gcd(g, a[i]);
    return g == k;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        rep(i, 1, n) ans[i] = 0, e[i].clear();
        ref(i, 1, n)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v), e[v].push_back(u);
        }
        rep(i, 1, n) du[i] = e[i].size();
        ans[1] = Pow(2, n - 1);
        ref(i, 2, n) if ((n - 1) % i == 0) ans[1] -= ans[i] = check(i);
        ans[1] = (ans[1] + MOD) % MOD;
        rep(i, 1, n) cout << ans[i] << ' ';
        cout << '\n';
    }
    return 0;
}