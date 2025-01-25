#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 23;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int fast_pow(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return ans;
}

int n;
int del[2][N];
vector<int> e[2][N];

int sum;
int vis[2][N];

void dfs0(int u, int fa)
{
    vis[0][u] = 1;
    for (auto v : e[0][u])
        if (v != fa && !del[0][v] && !vis[0][v])
            dfs0(v, u);
}
void dfs1(int u, int fa)
{
    vis[1][u] = 1;
    for (auto v : e[1][u])
        if (v != fa && !del[1][v] && !vis[1][v])
            dfs1(v, u);
}

void dg(int k)
{
    if (k > n)
    {
        memset(vis, 0, sizeof(vis));
        int cnta = 0, cntb = 0;
        rep(i, 1, n) if (!vis[0][i] && !del[0][i]) dfs0(i, 0), cnta++;
        rep(i, 1, n) if (!vis[1][i] && !del[1][i]) dfs1(i, 0), cntb++;
        sum = (sum + cnta * cntb) % MOD;
        // cout << sum << '\n';
        return;
    }

    del[0][k] = 1;
    dg(k + 1);
    del[0][k] = 0;

    del[1][k] = 1;
    dg(k + 1);
    del[1][k] = 0;
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
        e[0][u].push_back(v);
        e[0][v].push_back(u);
    }
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        e[1][u].push_back(v);
        e[1][v].push_back(u);
    }
    dg(1);
    // cout << sum << '\n';
    sum = sum * fast_pow(fast_pow(2, n), MOD - 2) % MOD;
    cout << sum << '\n';
    return 0;
}