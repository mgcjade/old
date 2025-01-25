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

int T;
int n;
int l, r;
int k;
int a[N];
int b[N], c[N];
int sumb, sumc;
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> l >> r;
        k = r - l + 1;
        rep(i, 1, n) cin >> a[i];
        rep(i, 1, n) b[i] = c[i] = a[i];
        sort(b + 1, b + r + 1);
        sort(c + l, c + n + 1);
        sumb = sumc = 0;
        rep(i, 1, k) sumb += b[i], sumc += c[l + i - 1];
        ans = min(sumb, sumc);
        cout << ans << "\n";
    }
    return 0;
}