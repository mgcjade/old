#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
vector<int> e[N];

int vis[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    if (n != m)
        return cout << "No\n", 0;
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int k = 1;
    int cnt = 0;
    vis[k] = 1;
    do
    {
        if (e[k].size() != 2)
            return cout << "No\n", 0;
        if (vis[e[k][0]] == 0)
        {
            k = e[k][0];
            vis[k] = 1;
        }
        else if (vis[e[k][1]] == 0)
        {
            k = e[k][1];
            vis[k] = 1;
        }
        else if (k != e[1][1])
            return cout << "No\n", 0;
        else
            k = 1;
        ++cnt;
    } while (k != 1);
    // cerr << cnt;
    if (cnt != n)
        return cout << "No\n", 0;
    cout << "Yes\n";
    return 0;
}