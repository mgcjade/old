#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 3.7e7 + 5;
const int s = 3e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

template <class _Tp>
_Tp Pow(_Tp a, _Tp b = MOD - 2, _Tp p = MOD)
{
    _Tp res = 1;
    while (b)
    {
        (b & 1) && (res = (ll)res * a % p);
        a = (ll)a * a % p, b >>= 1;
    }
    return res;
}

int n, k;
int x, y;
int p, bz[N], sum[N];
int a[N];
int ans;

void solve()
{
    cin >> n;
    k = 0, p = 0, sum[0] = 1;
    ref(i, 0, 3e5) bz[i] = 0;
    if (n < 37000000)
    {
        rep(i, 1, n)
        {
            cin >> a[i];
            bz[a[i]] = 1;
            while (bz[k])
                ++k;
        }
    }
    else
    {
        cin >> x >> y;
        a[1] = 0, k = 1, bz[0] = 1;
        rep(i, 2, n)
        {
            a[i] = (a[i - 1] * x + y + i) & 262143, bz[a[i]] = 1;
            while (bz[k])
                ++k;
        }
    }
    if (!k)
    {
        cout << Pow(2, n - 1) << '\n';
        return;
    }
    ref(i, 0, 3e5) bz[i] = 0;
    x = 1;
    rep(i, 1, n)
    {
        ++bz[a[i]];
        sum[i] = sum[i - 1];
        while (bz[p])
            ++p;
        if (p == k)
        {
            while (a[x] > k || a[x] < k && bz[a[x]] > 1)
                --bz[a[x++]];
            sum[i] = (sum[i] + sum[x - 1]) % MOD;
        }
    }
    cout << sum[x - 1] << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}