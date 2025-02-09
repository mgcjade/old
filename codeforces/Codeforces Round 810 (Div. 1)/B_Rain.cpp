#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct node
{
    int l, mid, r, x, p;
} a[N];
int n;
int c[N * 3], v[N * 3], m, b[N * 3];
int L, R;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        rep(i, 1, b[0]) c[i] = 0, v[i] = 0;
        b[0] = 0;
        cin >> n >> m;
        rep(i, 1, n)
        {
            int x, y;
            cin >> x >> y;
            a[i].x = x, a[i].p = y, a[i].l = x - y + 1;
            b[++b[0]] = a[i].l, a[i].mid = x + 1, b[++b[0]] = a[i].mid, a[i].r = x + y + 1, b[++b[0]] = a[i].r;
        }
        sort(b + 1, b + b[0] + 1);
        b[0] = unique(b + 1, b + b[0] + 1) - b - 1;
        rep(i, 1, n)
        {
            a[i].l = lower_bound(b + 1, b + b[0] + 1, a[i].l) - b, a[i].mid = lower_bound(b + 1, b + b[0] + 1, a[i].mid) - b, a[i].r = lower_bound(b + 1, b + b[0] + 1, a[i].r) - b;
            c[a[i].l]++, c[a[i].mid] -= 2, c[a[i].r]++;
        }
        rep(i, 1, b[0]) c[i] += c[i - 1];
        L = -1e18, R = -1e18;
        rep(i, 1, b[0])
        {
            v[i] = v[i - 1] + c[i - 1] * (b[i] - b[i - 1]);
            if (v[i] > m)
                L = max(L, v[i] - b[i] + 1), R = max(R, v[i] + b[i] - 1);
        }
        rep(i, 1, n)
        {
            if (L <= m + a[i].p - a[i].x && R <= m + a[i].p + a[i].x)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
    return 0;
}