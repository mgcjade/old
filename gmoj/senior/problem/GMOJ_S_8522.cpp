#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll a, b, c, d;
ll ans;

void solve()
{
    ans = 0;
    cin >> a >> b >> c >> d;
    while (1)
    {
        if (a > c || b > d)
        {
            cout << -1 << '\n';
            return;
        }
        if (a == c && b == d)
        {
            cout << ans << '\n';
            return;
        }
        if (a == c)
        {
            if ((d - b) % a == 0)
                cout << ans + (d - b) / a << '\n';
            else
                cout << -1 << '\n';
            return;
        }
        if (b == d)
        {
            if ((c - a) % b == 0)
                cout << ans + (c - a) / b << '\n';
            else
                cout << -1 << '\n';
            return;
        }
        if (c > d)
        {
            ans += c / d;
            c %= d;
        }
        else
        {
            ans += d / c;
            d %= c;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}