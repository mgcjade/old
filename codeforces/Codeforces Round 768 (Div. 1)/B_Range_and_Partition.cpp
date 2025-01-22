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

int T;
int n, k;
int a[N], b[N];

void solve()
{
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) b[i] = a[i];
    sort(b + 1, b + n + 1);
    int ansx, ansy, mn = INF;
    int l = 1, r = n - (n - k) / 2;
    while (l <= n && r <= n)
    {
        if (b[r] - b[l] < mn)
        {
            mn = b[r] - b[l];
            ansx = b[l];
            ansy = b[r];
        }
        l++, r++;
    }
    cout << ansx << " " << ansy << "\n";
    int cnta = 0, cntb = 0;
    int lst = 1, flag = 0;
    rep(i, 1, n)
    {
        if (flag == k - 1)
            break;
        if (ansx <= a[i] && a[i] <= ansy)
            cnta++;
        else
            cntb++;
        if (cnta > cntb)
        {
            flag++;
            cout << lst << ' ' << i << '\n';
            lst = i + 1;
            cnta = cntb = 0;
        }
    }
    cout << lst << ' ' << n << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}