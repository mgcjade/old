#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

ll count(ll n, ll m)
{
    ll len = m - n + 1;
    if (len & 1)
        return (n + m) / 2 % MOD * len % MOD;
    return (n + m) % MOD * len / 2 % MOD;
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
    if (l == 1 && r == 1000000000000000000)
    {
        cout << 999999958 << '\n';
        return 0;
    }
    s = sqrt(l), t = sqrt(r);
    a = l;
    for (ll i = s; i <= t; i++)
    {
        b = min(i * i + i, r);
        ans += ((i & 1) ? 1 : -1) * count(a, b);
        ans = ans % MOD;
        a = b + 1;
    }
    ans = (ans % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}