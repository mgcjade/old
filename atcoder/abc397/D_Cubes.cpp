#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

bool lpjh(int n)
{
    if (n < 0)
        return false;
    int s = sqrt(n);
    return (s * s == n);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int mx = cbrt(4 * n) + 2;
    rep(a, 1, mx)
    {
        if (n % a != 0)
            continue;
        int b = n / a;
        int tmp = 4 * b - a * a;
        if (tmp < 0 || tmp % 3 != 0)
            continue;
        int s = tmp / 3;
        if (!lpjh(s))
            continue;
        int k = sqrt(s);
        if ((k - a) % 2 != 0)
            continue;
        int y = (k - a) / 2;
        if (y <= 0)
            continue;
        int x = y + a;
        cout << x << ' ' << y;
        return 0;
    }
    cout << -1;
    return 0;
}