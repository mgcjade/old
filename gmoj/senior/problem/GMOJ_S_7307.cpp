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
const int MOD = 998244353;

int n, m;
int a[N + 5], b[N + 5];
int du[N + 5];
vector<int> e[N + 5];
int ans;

int check()
{
    rep(i, 1, n) for (auto j : e[i]) if (b[i] == b[j]) return 0;
    return 1;
}

void dg(int x)
{
    if (x > n)
    {
        ans += check();
        return;
    }
    rep(i, 1, a[x]) b[x] = i, dg(x + 1);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v), e[v].push_back(u);
        du[u]++, du[v]++;
    }
    dg(1);
    ans %= MOD;
    cout << ans << "\n";
    return 0;
}