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

int a[1005];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int t;
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> t;
        a[t] = 1;
    }
    int sum = n;
    rep(i, 1, n) sum -= a[i];
    cout << sum << '\n';
    rep(i, 1, n) if (a[i] == 0) cout << i << ' ';
    cout << '\n';
    return 0;
}