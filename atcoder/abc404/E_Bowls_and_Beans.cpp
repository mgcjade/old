#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int ans;
int c[N];
int a[N];

int f[N];
int cnt(int x, int y)
{
    rep(i, x, y) f[i] = INF;
    f[y] = 0;
    reb(i, y, x + 1) rep(j, 1, min(c[i], i - x)) f[i - j] = min(f[i - j], f[i] + 1);
    return f[x];
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    n -= 1;
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> a[i];
    int flag = n - 1, k = n;
    while (k && a[k] == 0)
        k--;
    flag = k - 1;
    while (flag && a[flag] == 0)
        flag--;
    while (k)
    {
        if (k - flag <= c[k])
        {
            ans++;
            k = flag;
            flag--;
        }
        else
        {
            ans += cnt(flag, k);
            k = flag;
            flag--;
        }
        while (flag && a[flag] == 0)
            flag--;
    }
    cout << ans << '\n';
    return 0;
}