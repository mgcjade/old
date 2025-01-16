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

ll getmax(ll x)
{
    ll res = 0;
    while (x)
    {
        res = max(res, x % 10);
        x /= 10;
    }
    return res;
}
ll a, m, n;

signed main()
{
    cin >> a >> m >> n;
    while (--n)
    {
        a = (a + getmax(a)) % m;
    }
    cout << a << '\n';
    return 0;
}