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

int T;
int n;
array<int, 2> a[N];
int flag, x, y;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        n++;
        cin >> flag;
        if (flag == 1)
        {
            cin >> x >> y;
            a[n] = {x, y};
        }
        else if (flag == 2)
        {
            cin >> x;
            a[x] = {0, 0};
        }
        else
        {
            cin >> x >> y;
            ll ans = 0;
            rep(i, 1, n) ans = max(ans, 1ll * a[i][0] * x + 1ll * a[i][1] * y);
            cout << ans << '\n';
        }
    }
    return 0;
}