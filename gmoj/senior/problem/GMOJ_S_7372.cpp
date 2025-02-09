#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 4e3 + 5;
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

int n, m;
int v[N];
int f[N][N], g[N][N];
int ans;
int pw[N];

void init()
{
    cin >> n >> m;
    int sum = 0;
    ref(j, 0, m) cin >> v[j];
    ref(j, 0, m) sum = (sum + v[j]) % MOD;
    sum = Pow(sum);
    ref(j, 0, m) v[j] = v[j] * sum % MOD;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init();

    int s = m + n;
    pw[0] = 1;
    rep(i, 1, s + 1) pw[i] = pw[i - 1] * 2 % MOD;
    rep(i, 1, n) rep(j, 0, s)
    {
        if (j < m)
            f[i][j] = v[j];
        if (j > 0)
            f[i][j] = (f[i][j] + f[i][j - 1] * f[i - 1][j - 1] % MOD) % MOD;
    }
    // rep(i, 1, n)
    // {
    //     rep(j, 1, s) cout << f[i][j] << ' ';
    //     cout << '\n';
    // }

    g[0][s] = 1;
    rep(i, 1, n)
    {
        int _sum = 0, cnt = 0;
        reb(j, s, 0) g[i][j] = (g[i][j] + _sum * f[n - i + 1][j] % MOD) % MOD, _sum = (_sum + g[i - 1][j]) % MOD;
        _sum = g[i - 1][0];
        rep(j, 1, s)
        {
            cnt = (cnt * f[n - i][j - 1] % MOD + _sum * v[j] % MOD) % MOD;
            g[i][j] = (g[i][j] + cnt) % MOD;
            _sum = (_sum + g[i - 1][j]) % MOD;
            // cout << g[i][j] << ' ';
        }
        // cout << '\n';
        rep(j, 0, s)
            ans = (ans + g[i][j] * f[n - i][j] % MOD * pw[j + 1] % MOD) % MOD;
    }
    cout << ans << '\n';
    return 0;
}