#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n, p, q;
int v, g;
int ans;

signed main()
{
    cin >> n >> p >> q;
    if (p * 2 < q)
        p = q - p;
    v = p * fast_pow(q, MOD - 2) % MOD;
    g = 1 - v + MOD;
    p = fast_pow(g, n);
    ans = v * (fast_pow(v, n) - p) % MOD + p + 2 * v % MOD * g % MOD * (fast_pow(2 * v, n) - p) % MOD * fast_pow(3 * v - 1, MOD - 2) % MOD;
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}