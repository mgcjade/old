#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
struct edge
{
    int to, nxt;
};
edge e[N];
int head[N], tot;
void add_egde(int u, int v)
{
    e[++tot] = {v, head[u]};
    head[u] = tot;
}
int x, y;
int ans;

int dep[N];
int cnt, sum;
bool flag;
void dfs(int k)
{
    int t;
    cnt++;
    if (dep[k] & 1)
        sum += a[k];
    else
        sum -= a[k];
    for (int i = head[k]; i; i = e[i].nxt)
    {
        t = e[i].to;
        if (dep[t])
        {
            if ((dep[k] & 1) == (dep[t] & 1))
                flag = true;
        }
        else
        {
            dep[t] = dep[k] + 1;
            dfs(t);
        }
    }
}
int cal(int u, int v)
{
    int ret, tmp;
    tmp = u % v;
    ret = u / v;
    return tmp * (ret + 1) * (ret + 1) + (v - tmp) * ret * ret;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        a[i] -= b[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add_egde(x, y);
        add_egde(y, x);
    }
    for (int i = 1; i <= n; i++)
    {
        if (dep[i])
            continue;
        sum = 0, cnt = 0;
        flag = false;
        dep[i] = 1;
        dfs(i);
        sum = abs(sum);
        if (flag)
            ans += sum & 1;
        else
            ans += cal(sum, cnt);
    }
    cout << ans;
    return 0;
}