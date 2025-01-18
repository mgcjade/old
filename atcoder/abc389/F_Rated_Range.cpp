#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 5e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;

int tre[2 * N + 10];
int lowbit(int x) { return x & (-x); }
void add(int val, int x)
{
    while (x <= N)
    {
        tre[x] += val;
        x += lowbit(x);
    }
}
int sum(int x)
{
    int res = 0;
    while (x > 0)
    {
        res += tre[x];
        x -= lowbit(x);
    }
    return res;
}

int fnd1(int x)
{
    int l = 0, r = N + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int tmp = sum(mid);
        if (tmp < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}
int fnd2(int x)
{
    int l = 0, r = N + 1;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        int tmp = sum(mid);
        if (tmp > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return r;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, N) add(1, i);
    int a, b;
    int l, r;
    rep(i, 1, n)
    {
        cin >> a >> b;
        l = max(1, fnd1(a)), r = fnd2(b);
        add(1, l), add(-1, r + 1);
        // cout << l << ' ' << r << ' ';
        // cout << sum(1) << ' ' << sum(1995) << '\n';
        // if (i == 3)
        // {
        // cout << sum(1197) << ' ' << sum(1198) << '\n';
        // rep(i, 1, N) cout << tre[i] << ' ';
        // }
    }
    int q;
    cin >> q;
    while (q--)
    {
        cin >> n;
        cout << sum(n) << '\n';
    }
    return 0;
}