#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

string n;
int len;
ll ans;
ll pw2[N + 5], pw3[N + 5];
int cnt;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    len = n.length();
    pw2[0] = 1, pw3[0] = 1;
    rep(i, 1, len) pw2[i] = pw2[i - 1] * 2 % MOD, pw3[i] = pw3[i - 1] * 3 % MOD;
    ll ans = pw3[len - 1];
    ref(i, 0, len) cnt += n[i] == '1';
    if (cnt == 1)
    {
        ans = (ans + pw2[len - 1] * 2) % MOD;
        cout << ans << '\n';
        return 0;
    }
    ans = (ans + pw2[len - cnt] * 2) % MOD;
    // cout << ans << '\n';
    reb(i, len - 1, 1)
    {
        if (n[i] == '1')
            cnt--, ans = (ans + pw2[i - cnt + 1] * pw3[len - i - 1] % MOD * 2) % MOD;
        // cout << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}