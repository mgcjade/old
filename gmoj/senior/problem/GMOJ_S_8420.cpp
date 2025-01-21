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

int n;
int a[N];
int b[N];
int ans = 1;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    ref(i, 1, n) b[i] = a[i + 1] / a[i];
    sort(b + 1, b + n);
    ref(i, 1, n)(b[i] != b[i + 1]) && (ans = max(ans, (int)(ceil)(log(i + 1) / log(b[i]))));
    cout << ans << '\n';
    // fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}