#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 2e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N];

int q[N];
int check(int k)
{
    int poi = k + 1, tmp = 0;
    int qh = 0, qt = -1;
    rep(j, 0, k)
    {
        q[++qt] = a[j + 1];
        if (a[j + 1] >= j)
            poi = j, tmp += a[j + 1] - j;
        else
            tmp += j - a[j + 1];
    }
    if (tmp <= m)
        return 1;
    rep(i, 2, n - k)
    {
        tmp -= abs(q[qh] - 0), qh++, tmp = tmp - (poi ? (poi - 1) : 0) + (k + 1 - poi);
        q[++qt] = a[i + k], tmp += abs(q[qt] - k);
        if (tmp <= m)
            return 1;
        while ((q[qh + poi - 1] >= poi - 1) && (poi - 1 >= 0))
            poi--;
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    // rep(i, 1, n) a[i] -= i;
    int l = 0, r = n - 1;
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            ans = mid, l = mid + 1;
        else
            r = mid - 1;
    }
    cout << ans + 1 << '\n';
    return 0;
}