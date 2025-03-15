#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e7;
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
int pw[N + 5];

int n, m, k;
int f[2][N + 5];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    rep(i, 1, N) pw[i] = Pow(i, m);
    f[0][0] = 1;
    rep(i, 1, k)
    {
        rep(j, i, n)
        {
            f[i & 1][j] = 0;
            ref(t, i - 1, j)
                f[i & 1][j] = (f[i & 1][j] + 1ll * f[(i - 1) & 1][t] * pw[j - t]) % MOD;
            // cerr << f[i & 1][j] << ' ';
        }
        // cerr << '\n';
    }
    cout << f[k & 1][n] << '\n';
    return 0;
}