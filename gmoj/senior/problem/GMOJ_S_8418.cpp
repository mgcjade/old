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

bool check(ll x)
{
    ll t = x;
    int len = 0;
    string str;
    while (t)
    {
        len++;
        str += t % 10 + '0';
        t /= 10;
    }
    ref(i, 0, len / 2) if (str[i] != str[len - i - 1]) return 0;
    return 1;
}
ll n;
ll ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 0, n) if (check(i) && check(n - i))
    {
        // cout << i << ' ' << n - i << '\n';
        ans++;
    }
    cout << ans << '\n';
    return 0;
}