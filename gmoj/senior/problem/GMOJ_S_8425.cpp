#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n, k;
int f[N][2];
int a[N];
vector<int> e[N];
int ans;

void dfs(int u, int fa)
{
    f[u][0] = f[u][1] = 0;
    for (auto v : e[u])
    {
        if (v == fa)
            continue;
        dfs(v, u);
        int tmp1 = f[u][0], tmp2 = f[u][1];
        f[u][0] = max(f[u][0], tmp1 + f[v][0]);
        if (tmp2 & 1 && f[v][1] & 1)
            f[u][0] = max(f[u][0], tmp2 + f[v][1]);
        if (f[v][1] & 1)
            f[u][1] = max(f[u][1], tmp1 + f[v][1]);
        if (tmp2 & 1)
            f[u][1] = max(f[u][1], tmp2 + f[v][0]);
    }
    if (f[u][0] & 1)
        f[u][0] = 0;
    if (!(f[u][1] & 1))
        f[u][1] = 0;
    int tmp1 = f[u][0], tmp2 = f[u][1];
    if (a[u] & 1)
    {
        if (tmp2 & 1)
            f[u][0] = tmp2 + a[u];
        else
            f[u][0] = 0;
        f[u][1] = tmp1 + a[u];
    }
    else
    {
        f[u][0] = tmp1 + a[u];
        if (tmp2 & 1)
            f[u][1] = tmp2 + a[u];
        else
            f[u][1] = 0;
    }
    if (f[u][0] & 1)
        f[u][0] = 0;
    if (!(f[u][1] & 1))
        f[u][1] = 0;
    // cout << u << ' ' << f[u][0] << ' ' << f[u][1] << '\n';
    if (f[u][k & 1] >= k)
        ans++, f[u][0] = f[u][1] = -INF;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n >> k;
        rep(i, 1, n) cin >> a[i];
        ref(i, 1, n)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        dfs(1, 0);
        cout << ans << '\n';
        rep(i, 1, n) e[i].clear();
    }
    return 0;
}