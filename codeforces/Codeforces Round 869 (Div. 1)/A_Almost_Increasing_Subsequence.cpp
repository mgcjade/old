#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int q;
int a[N];
int f[N];
int g1[N], g2[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    g1[1] = 1;
    rep(i, 2, n)
    {
        if (a[i] <= a[i - 1])
            g1[i] = g1[i - 1] + 1;
        else
            g1[i] = 1;
        f[i] = f[i - 1] + (g1[i] >= 3 ? 1 : 0);
    }
    g2[n] = 1;
    reb(i, n - 1, 1)
    {
        if (a[i] >= a[i + 1])
            g2[i] = g2[i + 1] + 1;
        else
            g2[i] = 1;
    }

    // rep(i, 1, n) cout << f[i] << ' ';
    // cout << '\n';
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        if (g1[l] == 1)
            cout << (r - l + 1) - (f[r] - f[l - 1]) << '\n';
        else
        {
            int tmp = g2[l];
            if (l + tmp - 1 > r)
                tmp = r - l + 1;
            cout << (r - l + 1) - (f[r] - f[l + tmp - 1] + max(0, tmp - 2)) << '\n';
        }
    }

    return 0;
}