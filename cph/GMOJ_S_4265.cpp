#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 998244353;

int n, m;
int k;
int T;
ll f[N];
int gcd[N];
int x, y, z;
ll ans = 1;

ll fastpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    k = min(n, m);
    for (int i = 1; i <= k; i++)
        cin >> f[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            gcd[__gcd(i, j)]++;
    for (int i = 1; i <= k; i++)
        if (gcd[i] != 0)
            ans = ans * fastpow(f[i] % MOD, gcd[i]);
    cout << ans << '\n';
    cin >> T;
    while (T--)
    {
        ans = 1;
        cin >> x >> y >> z;
        for (int i = x; i <= y; i++)
            f[i] = f[i] * z % MOD;
        for (int i = 1; i <= k; i++)
            if (gcd[i] != 0)
                ans = ans * fastpow(f[i] % MOD, gcd[i]);
        cout << ans << '\n';
    }
    return 0;
}