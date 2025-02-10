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

int n;
int a[N];
int ans[N];
int solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    if (n & 1)
        return cout << "NO\n", 0;
    int flag = 0;
    sort(a + 1, a + n + 1);
    // if (a[n / 2] == a[n / 2 + 1])
    //     return cout << "NO\n", 0;
    rep(i, 1, n / 2) ans[i * 2 - 1] = a[i], ans[i * 2] = a[i + n / 2];
    rep(i, 1, n / 2) if (ans[i * 2 - 1] >= ans[i * 2] || ans[i * 2 % n + 1] >= ans[i * 2]) flag = 1;
    if (flag)
        return cout << "NO\n", 0;
    cout << "YES\n";
    rep(i, 1, n) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}