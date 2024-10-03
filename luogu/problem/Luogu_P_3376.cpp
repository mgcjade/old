#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 2e2 + 5;
const int M = 5e3 + 5;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, st, en;
int ans;
int nw[N];
struct edge
{
    int to, nxt;
    int val;
} e[M << 1];
int hd[N], cnt;
inline void add(int x, int y, int z)
{
    e[cnt] = (edge){y, hd[x], z};
    hd[x] = cnt;
    cnt++;
}

int dis[N];
queue<int> q;
inline bool bfs()
{
    while (!q.empty())
        q.pop();
    for (register int i = 1; i <= n; i++)
        dis[i] = INF;
    q.push(st);
    dis[st] = 0;
    nw[st] = hd[st];
    int v, h;
    while (!q.empty())
    {
        h = q.front();
        q.pop();
        for (register int i = hd[h]; i > -1; i = e[i].nxt)
        {
            v = e[i].to;
            if (e[i].val > 0 && dis[v] == INF)
            {
                q.push(v);
                nw[v] = hd[v];
                dis[v] = dis[h] + 1;
                if (v == en)
                    return 1;
            }
        }
    }
    return 0;
}
inline int dfs(int k, int sum)
{
    if (k == en)
        return sum;
    int lst, res = 0;
    int v;
    for (register int i = nw[k]; i > -1 && sum; i = e[i].nxt)
    {
        nw[k] = i;
        v = e[i].to;
        if (e[i].val > 0 && (dis[v] == dis[k] + 1))
        {
            lst = dfs(v, min(sum, e[i].val));
            if (lst == 0)
                dis[v] = INF;
            e[i].val -= lst;
            e[i ^ 1].val += lst;
            sum -= lst;
            res += lst;
        }
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(hd, -1, sizeof(hd));
    cin >> n >> m >> st >> en;
    for (register int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
        add(y, x, 0);
    }
    while (bfs())
        ans += dfs(st, INF);
    cout << ans << '\n';
    return 0;
}