#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int cnt[N];

signed main()
{
    cin >> n >> m;
    n >>= 1, m >>= 1;
    rep(i, 1, n) rep(j, 0, m) cnt[i * i + j * j]++;
    int s = min(n, m);
    s *= s;
    int ans = 0;
    rep(i, 1, s) ans = max(ans, cnt[i]);
    // rep(i, 1, s) cout << cnt[i] << ' ';
    cout << ans * 4 << '\n';
    return 0;
}