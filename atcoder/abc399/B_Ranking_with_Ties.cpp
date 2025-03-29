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
pair<int, int> a[N];
int ans[N];

signed main()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    rep(i, 1, n) if (a[i].first == a[i - 1].first) ans[a[i].second] = ans[a[i - 1].second];
    else ans[a[i].second] = i;
    rep(i, 1, n) cout << ans[i] << "\n";
    return 0;
}