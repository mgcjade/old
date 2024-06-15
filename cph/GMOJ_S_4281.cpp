#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 3e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int cl[N];
ll f[N][3];
int x, y, z;
struct edge
{
    int to, w;
};
edge t;
vector<edge> e[N];

bool vis[N];
void dfs(int k)
{
    vis[k] = true;
    // if (e[k].size() <= 1)
    // {
    // if (cl[k] == 0)
    // {
    //     f[k][0] = INF;
    //     f[k][1] = 0;
    //     f[k][2] = 0;
    // }
    // else if (cl[k] == 1)
    // {
    //     f[k][0] = 0;
    //     f[k][1] = INF;
    //     f[k][2] = 0;
    // }
    // else
    // {
    //     f[k][0] = 0;
    //     f[k][1] = 0;
    //     f[k][2] = 0;
    // }
    //     return;
    // }
    ll sum = 0;
    int t = e[k].size();
    for (int i = 0; i < t; i++)
    {
        int v = e[k][i].to;
        if (!vis[v])
        {
            dfs(v);
            if (cl[k] != 0)
                f[k][0] += min(f[v][0], e[k][i].w + min(f[v][1], f[v][2]));
            if (cl[k] != 1)
                f[k][1] += min(f[v][1], e[k][i].w + min(f[v][0], f[v][2])), sum = max(sum, min(f[v][1], e[k][i].w + min(f[v][0], f[v][2])) - f[v][2]);
            if (cl[k] == 1)
                f[k][2] += min(f[v][1], e[k][i].w + min(f[v][0], f[v][2]));
        }
    }
    if (cl[k] == 0)
        f[k][0] = INF;
    if (cl[k] == 1)
        f[k][1] = INF;
    if (cl[k] != 1)
        f[k][2] = f[k][1] - sum;
}

int main()
{
    // memset(f, 0x3f, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fre(tree2);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> cl[i];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        t.to = y, t.w = z;
        e[x].push_back(t);
        t.to = x;
        e[y].push_back(t);
    }
    // for (int i = 1; i <= n; i++)
    //     for (int j = 0; j < e[i].size(); j++)
    //         cout << i << ' ' << e[i][j].to << ' ' << e[i][j].w << '\n';
    dfs(1);
    cout << min(f[1][0], min(f[1][1], f[1][2])) << "\n";
    // for (int i = 1; i <= n; i++)
    //     cout << f[i][0] << ' ' << f[i][1] << ' ' << f[i][2] << '\n';
    return 0;
}