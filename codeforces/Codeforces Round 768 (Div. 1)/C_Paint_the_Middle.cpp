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

int n;
int a[N];
int f[N];

int t[N], fir[N];
void modify(int l, int r, int k, int x, int v)
{
    if (l == r)
    {
        t[k] = max(t[k], v);
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
        modify(l, mid, k << 1, x, v);
    else
        modify(mid + 1, r, k << 1 | 1, x, v);
    t[k] = max(t[k << 1], t[k << 1 | 1]);
}
int query(int l, int r, int k, int x, int y)
{
    if (x <= l && r <= y)
        return t[k];
    int mid = (l + r) >> 1, res = -INF;
    if (x <= mid)
        res = max(res, query(l, mid, k << 1, x, y));
    if (y > mid)
        res = max(res, query(mid + 1, r, k << 1 | 1, x, y));
    return res;
}

signed main()
{
    memset(t, 0x80, sizeof(t));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    reb(i, n, 1) fir[a[i]] = i;
    f[1] = 0 - 1;
    modify(1, n, 1, 1, f[1]);
    rep(i, 2, n)
    {
        f[i] = query(1, n, 1, min(fir[a[i]], i - 1), i - 1) - 1;
        modify(1, n, 1, i, f[i]);
    }
    // rep(i, 1, n) cout << f[i] + i << ' ';
    cout << f[n] + n << '\n';
    // rep(i, 1, n) cout << fir[i] << ' ';
    // cout << '\n';
    return 0;
}