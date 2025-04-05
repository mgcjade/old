#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int a[N + 5], _Tp[N + 5];

void init()
{
    rep(i, 2, N) if (a[i] == 0) for (int j = i; j <= N; j += i) a[j]++;
    int mx = 0;
    rep(i, 2, N)
    {
        if (a[i] == 2)
            mx = max(mx, i);
        _Tp[i] = mx;
    }
}
void solve()
{
    int x, y;
    cin >> x;
    y = sqrtl(x);
    if (y * y > x)
        y--;
    y = min(y, N);
    int i = _Tp[y];
    cout << i * i << '\n';
    return;
}

signed main()
{
    init();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}