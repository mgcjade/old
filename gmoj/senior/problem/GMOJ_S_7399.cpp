#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long
#define pr pair<int, int>
#define PI 3.14159265358979323846

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

double jiaodu(pr a, pr b)
{
    double ret = atan2(b.second - a.second, b.first - a.first) * 180 / PI;
    if (ret < 0)
        ret = 360 + ret;
    return ret;
}
double len(pr a, pr b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int n, m, r;
pr point[N];
pair<double, int> th[N][N];
int cnt[N];
int ans;
void solve()
{
    ans = 0;
    rep(i, 1, n)
    {
        cnt[i] = 0;
        rep(j, 1, n) if (i != j && len(point[i], point[j]) <= r) th[i][++cnt[i]] = {jiaodu(point[i], point[j]), j};
    }
    rep(i, 1, n) sort(th[i] + 1, th[i] + cnt[i] + 1);
    rep(i, 1, n)
    {
        int x = 1, y = 1;
        while (x <= cnt[i])
        {
            int ny = y % cnt[i] + 1;
            double tp = th[i][ny].first - th[i][x].first;
            (tp < 0) && (tp += 360);
            while ((tp != 0 || ny > x) && ny != x && tp <= 30)
            {
                y = ny, ny = y % cnt[i] + 1;
                tp = th[i][ny].first - th[i][x].first, (tp < 0) && (tp += 360);
            }
            ans = max(ans, (y - x + cnt[i]) % cnt[i] + 1);
            if (y == x)
                y++;
            x++;
        }
    }
    cout << ans + 1 << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> n >> r)
    {
        m = n - 1;
        rep(i, 1, n) cin >> point[i].first >> point[i].second;
        solve();
    }
    // cerr << jiaodu({2, 1}, {1, 0}) << ' ' << atan2(-1, -1) * 180 / PI << '\n';
    return 0;
}

// 已知两个点A(x_A, y_A)和点B(x_B, y_B)，则两点所连成的直线与x轴形成的夹角θ为：atan2(y_B - y_A, x_B - x_A)
