#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, s;
int x, y;
vector<int> e[N];
int f[N], deep[N];

int dfs(int k, int fa)
{
    deep[k] = deep[fa] + 1;
    int mn = INF;
    for (int i = 0; i < e[k].size(); i++)
    {
        if (e[k][i] != fa)
        {
            mn = min(mn, dfs(e[k][i], k));
            f[k] = f[k] + f[e[k][i]];
        }
    }
    if (mn == INF)
        mn = deep[k];
    if ((mn - deep[k] + 1) <= deep[k])
        f[k] = 1;
    // cout << k << " " << f[k] << ' ' << mn << '\n';
    return mn;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s, s);
    cout << f[s] << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << ' ' << deep[i] << '\n';
    return 0;
}