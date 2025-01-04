#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 3e3;
const int M = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, m, ans = 1;
int a[N];
int low[N], dfn[N], p1, cnt, s[N], is[N], to[N], in[N], p[N];
int h[N], tot, h2[N], tot2;
int dp[N][N];

struct node
{
    int to, next;
} edge[M], edge2[M];

void add(int x, int y) { edge[++tot] = {y, h[x]}, h[x] = tot; }
void add2(int x, int y) { edge2[++tot2] = {y, h2[x]}, h2[x] = tot2; }

void dfs(int x)
{
    dfn[x] = low[x] = ++p1;
    s[++s[0]] = x, is[x] = 1;
    for (int i = h[x]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
            dfs(v), low[x] = min(low[x], low[v]);
        else if (is[v])
            low[x] = min(low[x], dfn[v]);
    }
    if (low[x] == dfn[x])
    {
        cnt++;
        while (1)
        {
            int pq = s[s[0]];
            s[0]--;
            to[pq] = cnt, is[pq] = 0;
            if (pq == x)
                break;
        }
    }
}

signed main()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i], add(i, a[i]);
    rep(i, 1, n) if (!dfn[i]) dfs(i);
    rep(i, 1, n) for (int j = h[i]; j; j = edge[j].next)
    {
        int v = edge[j].to;
        if (to[i] == to[v])
            continue;
        add2(to[i], to[v]);
        in[to[v]]++;
    }
    queue<int> q;
    rep(i, 1, cnt) rep(j, 1, m) dp[i][j] = 1;
    rep(i, 1, cnt) if (!in[i]) q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        int flag = 0;
        rep(j, 1, m)(dp[x][j] += dp[x][j - 1]) %= MOD;
        for (int i = h2[x]; i; i = edge2[i].next)
        {
            int v = edge2[i].to;
            in[v]--;
            rep(j, 1, m)
                dp[v][j] = dp[v][j] * dp[x][j] % MOD;
            if (!in[v])
                q.push(v);
            flag = 1;
        }
        if (!flag)
            ans = ans * dp[x][m] % MOD;
    }
    cout << ans;
    return 0;
}