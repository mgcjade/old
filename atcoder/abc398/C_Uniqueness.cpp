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

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i].first, a[i].second = i;
    sort(a + 1, a + 1 + n, greater<pair<int, int>>());
    rep(i, 1, n) if (a[i - 1].first != a[i].first && a[i].first != a[i + 1].first) return cout << a[i].second << '\n', 0;
    cout << -1;
    return 0;
}