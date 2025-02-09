#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, nxt[N];
int ans[N];
void solve()
{
    int mn = INF;
    cin >> n;
    rep(i, 1, n) cin >> nxt[i];
    rep(i, 1, n) ans[i] = 0;
    rep(i, 1, n) if (nxt[i] <= n) mn = min(mn, nxt[i] - i + 1);
    if (mn <= 1)
    {
        rep(i, 1, n) if (nxt[i] - i + 1 != mn)
        {
            cout << -1 << '\n';
            return;
        }
        rep(i, 1, n) cout << 1 << ' ';
        cout << '\n';
        return;
    }
    
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}