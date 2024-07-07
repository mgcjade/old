#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
struct node
{
    int to, nxt;
};
node edge[N << 1];
int head[N], cnt;
void add_edge(int u, int v)
{
    edge[++cnt] = {v, head[u]};
    head[u] = cnt;
}
int x, y;

bool vis[N];
int leaf[N], tot;
void dfs(int k)
{
    if (edge[head[k]].nxt == 0)
        leaf[++tot] = k;
    vis[k] = true;
    for (int i = head[k]; i; i = edge[i].nxt)
    {
        int v = edge[i].to;
        if (vis[v])
            continue;
        dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add_edge(x, y);
        add_edge(y, x);
    }
    dfs(1);
    cout << (tot + 1) / 2 << '\n';
    for (int i = 1; i * 2 <= tot; i++)
        cout << leaf[i] << ' ' << leaf[i + tot / 2] << '\n';
    if (tot & 1)
        cout << leaf[1] << ' ' << leaf[tot] << '\n';
    return 0;
}