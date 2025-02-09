#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 5e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int f[N];
int l[N], r[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        l[i] = i, r[i] = i;
        while (l[i] > 1 && a[l[i] - 1] > a[i])
            l[i]--;
        while (r[i] < n && a[r[i] + 1] > a[i])
            r[i]++;
        // cout << l[i] << ' ' << r[i] << '\n';
    }
    f[0] = 1;
    rep(i, 1, n) rep(j, l[i], r[i]) f[j] = (f[j] + f[j - 1]) % MOD;
    cout << f[n] << '\n';
    return 0;
}