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

int n, k;
int a[N];
int ans = 0;

int st[N], hd;
void solve(int x, int chose, int cnt)
{
    if (chose == k)
    {
        // cout << cnt << ' ';
        // ref(i, 0, hd)
        // {
        //     cout << st[i] << ' ';
        // }
        // cout << '\n';
        ans = max(ans, cnt);
        return;
    }
    rep(i, x + 1, n - k + chose + 1)
    {
        st[hd++] = a[i];
        solve(i, chose + 1, cnt ^ a[i]);
        hd--;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    solve(0, 0, 0);
    cout << ans << '\n';
    return 0;
}