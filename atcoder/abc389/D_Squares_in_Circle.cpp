#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, -n, n + 1)
    {
        double dn = n * n - (i - 0.5) * (i - 0.5);
        if (dn <= 0)
            continue;
        ans += 2 * (int)(sqrt(dn) + 0.5) - 2;
    }
    cout << ans + 1;
    return 0;
}
