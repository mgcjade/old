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
int u, v;
int ans;
set<int> e[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        if (u == v)
        {
            ans++;
            continue;
        }
        if (e[u].find(v) != e[u].end())
            ans++;
        e[u].insert(v);
    }
    cout << ans << "\n";
    return 0;
}