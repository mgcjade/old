#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
struct edge
{
    int u, v;
    int nxt;
};
edge e[N << 1];
int head[N], cnt;
void add(int u, int v)
{
    e[++cnt] = (edge){u, v, head[u]};
    head[u] = cnt;
}

int rd[N][N];
bool vis[N];
int q[N], hd, tl;
void bfs(int k)
{
    memset(vis, 0, sizeof(vis));
    vis[k] = 1;
    q[tl++] = k;
    rd[k][k] = 0;
    while (hd < tl)
    {
        int u = q[hd++];
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].v;
            if (!vis[v])
            {
                rd[k][v] = rd[k][u] + 1;
                vis[v] = 1;
                q[tl++] = v;
            }
        }
    }
}

struct node
{
    int a, b, d;
} a[N];
int u, v;

int main()
{
    // fre(nichijou);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    for (int i = 1; i <= m; i++)
        cin >> a[i].a >> a[i].b >> a[i].d;
    for (int i = 1; i <= n; i++)
        bfs(i);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         cout << rd[i][j] << " ";
    //     cout << "\n";
    // }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= m && flag; j++)
            if (rd[i][a[j].a] + rd[i][a[j].b] > a[i].d)
                flag = false;
        if (flag)
        {
            cout << i << "\n";
            return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}