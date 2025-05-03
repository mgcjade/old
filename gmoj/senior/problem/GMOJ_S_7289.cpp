#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e7;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
int p[N + 5];
int f[N + 5];

void init()
{
    p[2] = 1;
    rep(i, 3, N) p[i] = (i - 1) * (p[i - 1] + p[i - 2]) % MOD;
    f[2] = 1;
    rep(i, 3, N) f[i] = (i - 1) * (f[i - 1] + f[i - 2] + p[i - 2]) % MOD;
}

int ans;
void solve()
{
    cin >> n;
    ans = n * p[n] - f[n];
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
}

signed main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}