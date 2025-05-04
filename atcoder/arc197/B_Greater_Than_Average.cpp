#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int ans, sum, mid;
int cnt;
int solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ans = 0, sum = 0;
    sort(a + 1, a + n + 1);
    rep(i, 1, n) sum += a[i];
    mid = sum / n;
    int lst = 0;
    reb(i, n, 1) if (a[i] > mid) ans++, lst = i;
    if (lst == 0)
        return cout << 0 << '\n', 0;
    lst--, cnt = ans;
    reb(i, n, 2)
    {
        if (a[i] > mid)
            cnt--;
        sum -= a[i];
        mid = sum / (i - 1);
        while (a[lst] > mid && lst > 0)
        {
            cnt++;
            lst--;
        }
        if (lst >= i)
            lst = i - 1, cnt = 0;
        ans = max(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}