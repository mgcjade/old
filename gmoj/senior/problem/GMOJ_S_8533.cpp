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

int n, k, T, flag;
int a[N];
int x, y;
int ans;
priority_queue<pair<int, int>> q;
pair<int, int> mx;

void solve()
{
    while (!q.empty())
        q.pop();
    mx = {a[1], 1}, ans = 0;
    rep(i, 2, n)
    {
        if (a[i] > mx.first)
        {
            q.push(mx);
            mx = {a[i], i};
        }
        else
            q.push({a[i], i});
        while (mx.second + k < i)
        {
            mx = q.top();
            q.pop();
        }
        while (q.top().second + k < i)
            q.pop();
        ans = max(ans, mx.first + q.top().first);
    }
    cout << ans << '\n';
}

signed main()
{
    cin >> n >> k >> T >> flag;
    rep(i, 1, n) cin >> a[i];
    solve();
    while (T--)
    {
        cin >> x >> y;
        if (flag)
            x ^= ans, y ^= ans;
        a[x] = y;
        solve();
    }
    return 0;
}