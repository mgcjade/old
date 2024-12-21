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

ll fast_pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res;
}

ll l, r;
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    ans = (fast_pow(2, r - l + 1) - 1 + MOD) % MOD * fast_pow(2, l) % MOD;
    if (l & 1)
        ans = (ans - 2 + MOD) % MOD, ++l;
    if (!(r & 1))
        ans = (ans - 1 + MOD) % MOD, --r;
    ans = (ans - (r - l + 1 >> 1) * 3 % MOD + MOD) % MOD * fast_pow(3, MOD - 2) % MOD;
    cout << ans;
    // cout << ((fast_pow(2, r + 1) - 1) - (fast_pow(2, l) - 1)) << '\n';
    // cout << (3 * ((r - l + 1) >> 1)) + (((r - l + 1) & 1) == 0 ? ((r & 1) ^ 1) : 0) << '\n';
    return 0;
}