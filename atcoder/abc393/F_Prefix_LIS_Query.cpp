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

int n, q;
int a[N], d[N], f[N], c[N];
int ans[N];
vector<array<int, 2>> e[N];

void modify(int x, int val)
{
    for (; x <= n; x += x & -x)
        c[x] = max(c[x], val);
}
int query(int x)
{
    int ans = 0;
    for (; x; x -= x & -x)
        ans = max(ans, c[x]);
    return ans;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n)
    {
        cin >> a[i];
        d[i] = a[i];
    }
    sort(d + 1, d + n + 1);
    int m = unique(d + 1, d + n + 1) - d - 1;
    for (int i = 1, r, x; i <= q; ++i)
    {
        cin >> r >> x;
        e[r].push_back({x, i});
    }
    rep(i, 1, n)
    {
        a[i] = lower_bound(d + 1, d + m + 1, a[i]) - d;
        f[a[i]] = max(f[a[i]], query(a[i] - 1) + 1);
        modify(a[i], f[a[i]]);
        for (auto [x, id] : e[i])
            ans[id] = query(upper_bound(d + 1, d + m + 1, x) - d - 1);
    }
    rep(i, 1, q) cout << ans[i] << '\n';
}
