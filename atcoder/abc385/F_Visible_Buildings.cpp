#include <bits/stdc++.h>
using namespace std;
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
typedef long double db;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
db x[N + 5];

db h[N + 5];
db xl(db ax, db ay, db bx, db by)
{
    return (by - ay) / (bx - ax);
}
int _tab[N + 5];
int st[N + 5];
int _top;
db xj(db ax, db ay, db bx, db by)
{
    return ax * by - ay * bx;
}
db js(db a, db k)
{
    return -a * k;
}
int us[N + 5];
db ans = -10000000000;
db const esp = 1e-15;
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> x[i] >> h[i];
    }
    _top = 1;
    st[_top] = 1;
    rep(i, 1, n)
    {
        while (_top >= 2 && xj(x[st[_top]] - x[st[_top - 1]], h[st[_top]] - h[st[_top - 1]], x[i] - x[st[_top]], h[i] - h[st[_top]]) + esp > 0.0)
        {
            _top--;
        }
        _tab[i] = st[_top];
        _top++;
        st[_top] = i;
    }
    rep(i, 2, n)
    {
        ans = max(ans, -esp + h[i] + js(x[i], xl(x[_tab[i]], h[_tab[i]], x[i], h[i])));
    }
    if (ans + esp <= 0.0)
    {
        cout << -1;
        return 0;
    }
    cout << fixed << setprecision(18) << ans;
    return 0;
}