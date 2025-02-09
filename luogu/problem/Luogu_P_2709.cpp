#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, k;
int a[N];
int K;
int sum;

int cnt[N];
int ans[N];
struct Q
{
    int l, r, id;
    int x;
} q[N];
bool cmp(Q &a, Q &b)
{
    if (a.x == b.x)
        return a.r < b.r;
    // return (a.x & 1) ? a.r > b.r : a.r < b.r;
    // return (a.x & 1) ? a.r < b.r : a.r > b.r;
    return a.x < b.x;
}
void add(int x, int y)
{
    cnt[x] += y;
    sum += y * 2 * cnt[x] - 1;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    K = sqrt(n);
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, m) cin >> q[i].l >> q[i].r, q[i].id = i;
    rep(i, 1, m) q[i].x = q[i].l / K;
    sort(q + 1, q + m + 1, cmp);
    int l = 1, r = 0;
    rep(i, 1, m)
    {
        while (r < q[i].r)
            r++, add(a[r], 1);
        while (l > q[i].l)
            l--, add(a[l], 1);
        while (r > q[i].r)
            add(a[r], -1), r--;
        while (l < q[i].l)
            add(a[l], -1), l++;
        ans[q[i].id] = sum;
    }
    rep(i, 1, m) cout << ans[i] << '\n';
    // fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}