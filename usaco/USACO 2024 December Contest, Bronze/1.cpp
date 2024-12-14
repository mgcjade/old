#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int t, n;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        int tmp = 50, l = 45, r = 49, ans = 0;
        while (n >= r)
        {
            ans += r - l + 1;
            r = r * 10 + 9, l = l * 10 - 5;
            tmp *= 10;
        }
        if (n >= l)
            ans += (n - l + 1);
        cout << ans << '\n';
    }
}
