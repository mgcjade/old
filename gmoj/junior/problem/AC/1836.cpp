#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

const int N = 1e5 + 5;
const int M = 5e5 + 5;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

struct node
{
    int to, nxt;
};
node edge[M >> 1];
int hd[N], cnt;
inline void add(int a, int b)
{
    ++cnt;
    edge[cnt].to = b;
    edge[cnt].nxt = hd[a];
    hd[a] = cnt;
}

int f[N], mn[N];
int n, m;
int v[N];

bool vis[N];
inline void fnd_mn(int k)
{
    vis[k] = 1;
    for (int i = hd[k]; i; i = edge[i].nxt)
    {
        mn[edge[i].to] = min(mn[edge[i].to], mn[k]);
        if (mn[edge[i].to] < mn[k] || !vis[edge[i].to])
            fnd_mn(edge[i].to);
    }
}
inline void dfs(int k)
{
    vis[k] = 0;
    f[k] = max(f[k], v[k] - mn[k]);
    for (int i = hd[k]; i; i = edge[i].nxt)
    {
        f[edge[i].to] = max(f[edge[i].to], f[k]);
        if (f[edge[i].to] > f[k] || vis[edge[i].to])
            dfs(edge[i].to);
    }
}

int main()

{
    // fre(ans);
    read(n), read(m);
    for (int i = 1; i <= n; ++i)
    {
        read(v[i]);
        mn[i] = v[i];
    }
    int t, a, b;
    for (int i = 1; i <= m; ++i)
    {
        read(a), read(b), read(t);
        add(a, b);
        if (t == 2)
            add(b, a);
    }
    fnd_mn(1);
    dfs(1);
    printf("%d", f[n]);
    return 0;
}