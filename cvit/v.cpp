#include <bits/stdc++.h>
#define INF 2147483647
using namespace std;
const int N = 5e5 + 7;
int hed[N];
struct EDGE
{
    int frm, nxt;
} edge[N];
int cnt;
int n, m;
int a[N];
int xjg[N];
int f[N];
void add(int x, int y)
{
    edge[++cnt].nxt = y;
    edge[cnt].frm = hed[x];
    hed[x] = cnt;
}
void dfs(int x, int minn, int fa)
{
    bool bz = 1;
    minn = min(a[x], minn);
    if (xjg[x] > minn)
    {
        xjg[x] = minn;
        bz = 0;
    }
    int maxn = max(f[fa], a[x] - minn);
    if (f[x] < maxn)
    {
        f[x] = maxn;
        bz = 0;
    }
    if (bz)
        return;
    for (int i = hed[x]; i; i = edge[i].frm)
    {
        dfs(edge[i].nxt, minn, x);
    }
}
int main()
{
    freopen("trade.in", "r", stdin);
    freopen("trade.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        xjg[i] = INF;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y);
        if (z != 1)
            add(y, x);
    }
    dfs(1, INF, 0);
    printf("%d", f[n]);
}