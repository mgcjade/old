#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

ll count(ll n, ll m)
{
    return (((n + m) % MOD) * (m - n + 1) % MOD) * 500000004 % MOD;
}

ll l, r;
ll ans;
ll s, t;
ll a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l >> r;
    s = sqrt(l), t = sqrt(r - 1) + 1;
    a = l;
    for (ll i = s; i <= t; i++)
    {
        b = min(i * i + i, r);
        if (b < a)
            continue;
        ans += ((i & 1) ? 1 : -1) * count(a, b);
        ans = ans % MOD;
        // cout << ans << ' ' << count(a, b) << '\n';
        a = b + 1;
    }
    ans = (ans + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}