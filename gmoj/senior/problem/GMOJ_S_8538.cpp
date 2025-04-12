#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long
#define pr pair<int, int>

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

double S(pr a, pr b, pr c)
{
    // 求三角形面积
    return 1.0 * abs(a.first * b.second + b.first * c.second + c.first * a.second - a.first * c.second - b.first * a.second - c.first * b.second) / 2.0;
}

int n;
pr a[N], b[N], c[N];
int cnta, cntb, cntc;
double ans;
void solve()
{
    cnta = cntb = cntc = 0;
    int x, y, cl;
    cin >> n;
    rep(i, 1, n)
    {
        cin >> x >> y >> cl;
        if (cl == 0)
            a[++cnta] = {x, y};
        else if (cl == 1)
            b[++cntb] = {x, y};
        else
            c[++cntc] = {x, y};
    }
    ans = 0;
    rep(i, 1, cnta) rep(j, 1, cntb) rep(k, 1, cntc)
        ans = max(ans, S(a[i], b[j], c[k]));
    cout << fixed << setprecision(1) << ans << '\n';
    // cerr << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}