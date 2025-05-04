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

int jc[N + 5], inv[N + 5];
int ans[N + 5];
int f[N + 5], g[N + 5];
int sum[N + 5];

void init()
{
    jc[1] = 1, inv[1] = 1;
    rep(i, 2, N + 1) jc[i] = jc[i - 1] * i % MOD;
    rep(i, 2, N + 1) inv[i] = (MOD - MOD / i) * inv[MOD % i] % MOD;
    rep(i, 1, N)
    {
        f[i] = (f[i - 1] + (-i * i + i - 1ll) % MOD * inv[i]) % MOD;
        g[i] = (g[i - 1] + i * inv[i + 1]) % MOD;
    }
    rep(i, 1, N) ans[i] = (jc[i] * f[i] % MOD + jc[i + 1] * g[i]) % MOD;
    rep(i, 1, N) sum[i] = sum[i - 1] ^ ans[i];
}

signed main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int l, r;
    cin >> l >> r;
    cout << (sum[l - 1] ^ sum[r]) << '\n';
    return 0;
}