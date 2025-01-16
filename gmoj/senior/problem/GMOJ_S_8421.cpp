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

int n, m;
int x[N], y[N];
struct matrix
{
    int ux, uy;
    int dx, dy;
    void bing(matrix s)
    {
        // up
        if (ux > s.ux)
            swap(ux, s.ux), swap(uy, s.uy);
        if (abs(ux - s.ux) <= abs(uy - s.uy))
            ux = uy > s.uy ? s.ux : ux, uy = min(uy, s.uy);
        else
        {
            ux = ((s.uy - s.ux) - (ux + uy)) / (-2);
            uy = s.uy - (s.ux - ux);
        }
        // down
        if (dx > s.dx)
            swap(dx, s.dx), swap(dy, s.dy);
        if (abs(dx - s.dx) <= abs(dy - s.dy))
            dx = dy < s.dy ? s.dx : dx, dy = max(dy, s.dy);
        else
        {
            dx = ((s.dx + s.dy) - (dy - dx)) / 2;
            dy = s.dy + (s.dx - dx);
        }
    }
};
matrix ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> x[i] >> y[i];
    rep(i, 2, n) if ((x[i] + y[i] & 1) != (x[1] + y[1] & 1)) return cout << 0 << '\n', 0;
    ans = {x[1], y[1] + m, x[1], y[1] - m};
    rep(i, 2, n)
    {
        ans.bing({x[i], y[i] + m, x[i], y[i] - m});
    }
    if (ans.ux < ans.dx)
        return cout << 0 << '\n', 0;
    cout << ans.ux << ' ' << ans.uy << ' ' << ans.dx << ' ' << ans.dy << '\n';
    return 0;
}