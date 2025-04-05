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
const int MOD = 1e9 + 7;

template <class _Tp>
_Tp Pow(_Tp a, _Tp b = MOD - 2, _Tp p = MOD)
{
    _Tp res = 1;
    while (b)
    {
        (b & 1) && (res = (ll)res * a % p);
        a = (ll)a * a % p, b >>= 1;
    }
    return res;
}

int n, k;
int f[N + 5], g[N + 5];

void init()
{
    f[1] = 0, f[2] = 1;
    rep(i, 3, N) g[i] = (g[i - 1] + f[i - 2]) % MOD, f[i] = (f[i] + (1 + g[i]) * Pow(i - 1)) % MOD;
    rep(i, 1, N) g[i] = 1 + MOD - f[i];
}

void solve()
{
    cin >> n >> k;
    int ans = 1 - g[k] * g[n - k + 1] % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    init();
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}