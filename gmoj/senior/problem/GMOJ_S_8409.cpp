#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int to[N];
int ans;
int vis[N];

void dfs(int x, int step)
{
    vis[x] = step;
    if (vis[to[x]])
        return;
    dfs(to[x], step + 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) cin >> to[i];
    rep(i, 1, m) if (!vis[i]) dfs(i, 1);
    rep(i, 1, m) ans = max(ans, vis[i]);
    cout << ans << '\n';
    // fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}