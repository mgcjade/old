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

int n, m;
int a[N], b[N];
int suma[N], sumb[N];
int maxa[N];
int ans = -INF;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> b[i];
    sort(a + 1, a + n + 1, greater<int>()), sort(b + 1, b + m + 1, greater<int>());
    rep(i, 1, n) suma[i] = suma[i - 1] + a[i];
    rep(i, 1, m) sumb[i] = sumb[i - 1] + b[i];
    maxa[n] = suma[n];
    reb(i, n - 1, 0) maxa[i] = max(maxa[i + 1], suma[i]);
    rep(i, 0, m)
    {
        if (i > n)
            break;
        ans = max(ans, sumb[i] + maxa[i]);
    }
    cout << ans;
    return 0;
}