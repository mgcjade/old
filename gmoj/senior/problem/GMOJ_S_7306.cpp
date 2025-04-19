#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N + 5], b[N + 5];
vector<int> e[N + 5];

int dfs(int u, int fa)
{
    int sum = 0, cnt = 0;
    for (auto v : e[u])
        if (v != fa)
            cnt += dfs(v, u);
    for (int v : e[u])
        if (v != fa)
            sum += min(a[v], a[u]), cnt += max(a[v] - a[u], 0ll);
    if (sum <= a[u])
        return cnt;
    cnt += sum - a[u];
    a[u] = max(0ll, a[u] * 2ll - sum);
    return cnt;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ref(i, 1, n)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
    }
    e[0].push_back(1);
    cout << dfs(0, 0) << '\n';
    return 0;
}