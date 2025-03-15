#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 5e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

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
int x[N + 5], ny[N + 5];
int g[N + 5], f[N + 5];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    x[0] = 1, g[0] = 1, f[0] = 1;
    rep(i, 1, N) x[i] = x[i - 1] * k % MOD, g[i] = g[i - 1] * (x[i] - 1) % MOD;
    ny[n] = Pow(g[n]);
    reb(i, n - 1, 1) ny[i] = ny[i + 1] * (x[i + 1] - 1) % MOD;
    rep(i, 1, n) f[i] = f[i - 1] * (x[n] * k % MOD - x[i] + MOD) % MOD * g[i - 1] % MOD * ny[i] % MOD * i % MOD;
    rep(i, 1, n) cout << f[i] << '\n';
    return 0;
}