#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define reb(i, a, b) for (int i = a; i >= b; --i)
#define ref(i, a, b) for (int i = a; i < b; ++i)
using namespace std;
#define int long long

const int N = 1e5 + 1;
const double INF = 1e18;

int n;
int Q;
struct node
{
    int p;
    int time;
    int x;
} a[N];
double f[N][31][21];

pair<int, int> ask[N];
double ans[N];

int pw2[31], pw3[21];

signed main()
{
    pw2[0] = pw3[0] = 1;
    rep(i, 1, 30) pw2[i] = pw2[i - 1] * 2;
    rep(i, 1, 20) pw3[i] = pw3[i - 1] * 3;
    rep(i, 0, 30) rep(j, 0, 20) f[0][i][j] = INF;
    f[0][0][0] = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> Q;
    rep(i, 1, n)
    {
        cin >> a[i].p >> a[i].time >> a[i].x;
        (a[i].x == 1) && (--n, --i);
    }
    rep(i, 1, n) rep(j, 0, 30) rep(k, 0, 20)
    {
        f[i][j][k] = f[i - 1][j][k] + (a[i].p - a[i - 1].p) * 1.0 / (pw2[j] * pw3[k]);
        if (a[i].x == 2 && j)
            f[i][j][k] = min(f[i][j][k], f[i - 1][j - 1][k] + (a[i].p - a[i - 1].p) * 1.0 / (pw2[j - 1] * pw3[k]) + a[i].time);
        else if (a[i].x == 3 && k)
            f[i][j][k] = min(f[i][j][k], f[i - 1][j][k - 1] + (a[i].p - a[i - 1].p) * 1.0 / (pw2[j] * pw3[k - 1]) + a[i].time);
        else if (a[i].x == 4 && j > 1)
            f[i][j][k] = min(f[i][j][k], f[i - 1][j - 2][k] + (a[i].p - a[i - 1].p) * 1.0 / (pw2[j - 2] * pw3[k]) + a[i].time);
    }
    rep(i, 1, Q)
    {
        cin >> ask[i].first;
        ask[i].second = i;
        ans[i] = INF;
    }
    sort(ask + 1, ask + Q + 1);
    int i = 0;
    rep(j, 1, Q)
    {
        while (i < n && a[i + 1].p <= ask[j].first)
            i++;
        rep(k, 0, 30) rep(l, 0, 20) ans[ask[j].second] = min(ans[ask[j].second], f[i][k][l] + (ask[j].first - a[i].p) * 1.0 / (pw2[k] * pw3[l]));
    }
    rep(i, 1, Q) cout << fixed << setprecision(8) << ans[i] << '\n';
    fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}