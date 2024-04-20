// 述链剖分lca
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

vector<int> edge[N];
void add(int x, int y)
{
    edge[x].push_back(y);
}
int n, m, s;
int x, y;
int fa[N];
int hd[N], sz[N], son[N];
bool vis[N];
void made(int k)
{
    vis[k] = true;
    int t = edge[k].size();
    for (int i = 0; i < t; i++)
    {
        if (!vis[edge[k][i]])
        {
            fa[edge[k][i]] = k;
            sz[edge[k][i]] = sz[k] + 1;
            made(edge[k][i]);
            son[k] = son[k] + son[edge[k][i]];
        }
    }
    son[k]++;
}
void _made(int k)
{
    vis[k] = true;
    int t = edge[k].size();
    if (t <= 1)
        return;
    int mini = edge[k][0];
    for (int i = 1; i < t; i++)
    {
        if (son[edge[k][i]] > son[mini])
            mini = edge[k][i];
    }
    hd[mini] = hd[k];
    _made(mini);
    for (int i = 0; i < t; i++)
    {
        if (!vis[edge[k][i]] && edge[k][i] != mini)
            _made(edge[k][i]);
    }
}
void init()
{
    sz[s] = 1;
    fa[s] = s;
    for (int i = 1; i <= n; i++)
        hd[i] = i;
    made(s);
    memset(vis, 0, sizeof(vis));
    _made(s);
    // for (int i = 1; i <= n; i++)
    //     cout << i << " " << fa[i] << ' ' << hd[i] << ' ' << sz[i] << ' ' << son[i] << '\n';
}
int fnd(int a, int b)
{
    while (hd[a] != hd[b])
    {
        if (sz[hd[a]] <= sz[hd[b]])
            b = fa[hd[b]];
        else
            a = fa[hd[a]];
    }
    return sz[a] <= sz[b] ? a : b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    init();
    while (m--)
    {
        cin >> x >> y;
        cout << fnd(x, y) << '\n';
    }
    return 0;
}