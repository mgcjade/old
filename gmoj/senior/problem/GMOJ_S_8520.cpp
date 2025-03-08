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
int a[N];
int mx[N];
int mmx[N][20];
int mymax(int l, int r)
{
    int s = __lg(r - l + 1);
    return max(mmx[l][s], mmx[r - (1 << s) + 1][s]);
}
void solve()
{
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    reb(i, n, 1) mx[i] = max(mx[i + 1], a[i]);
    rep(i, 1, n) mmx[i][0] = a[i];
    int s = __lg(n);
    rep(j, 1, s + 1) rep(i, 1, n - (1 << j) + 1) mmx[i][j] = max(mmx[i][j - 1], mmx[i + (1 << (j - 1))][j - 1]);
    int lst = 0;
    rep(i, 1, n) if (mx[i] == a[i])
    {
        if (lst + 1 != i && mymax(lst + 1, i - 1) >= mx[i + 1])
        {
            int tmp = a[i];
            reb(j, i, lst + 2) a[j] = a[j - 1];
            a[lst + 1] = tmp;
            break;
        }
        lst = i;
    }
    reb(i, n, 1) mx[i] = max(mx[i + 1], a[i]);
    rep(i, 1, n) if (a[i] == mx[i]) cout << a[i] << ' ';
    // rep(i, 1, n) cerr << a[i] << ' ';
    cout << '\n';
    rep(j, 0, s + 1) rep(i, 1, n - (1 << j) + 1) mmx[i][j] = 0;
    rep(i, 1, n) mx[i] = 0;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}