#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 405;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

bitset<405> bxx, a[405], b[405];
int n, ans;
int jc[N];

int solve()
{
    cin >> n;
    rep(i, 1, n) a[i] = 0, b[i] = 0;
    rep(i, 1, n) rep(j, 1, n)
    {
        int x = 0;
        cin >> x;
        a[i][j] = x;
    }
    rep(i, 1, n) if (!a[1][i] || !a[i][1]) return cout << "0\n", 0;
    rep(i, 1, n) rep(j, 1, n)
    {
        int flag = 1;
        rep(k, 1, n) if (a[j][k] && (!a[i][k]))
        {
            flag = 0;
            break;
        }
        b[i][j] = flag;
    }
    rep(i, 1, n) rep(j, 1, n) if ((a[i][j] && (!(b[i][j] + b[j][i]))) || (!a[i][j] && (b[i][j] + b[j][i]))) return cout << "0\n", 0;
    bxx = 0, ans = 1;
    rep(i, 2, n) if (!bxx[i])
    {
        int cnt = 0;
        rep(j, 2, n) if (a[i] == a[j]) bxx[j] = 1, cnt++;
        ans = ans * jc[cnt] % MOD;
    }
    cout << ans << "\n";
    return 0;
}

signed main()
{
    jc[0] = 1;
    rep(i, 1, N - 1) jc[i] = jc[i - 1] * i % MOD;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}