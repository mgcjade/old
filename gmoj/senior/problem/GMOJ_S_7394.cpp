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

int n;
int p[N], q[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ref(i, 0, n) cin >> p[i];
    ref(i, 0, n) cin >> q[i];
    int ans = 0;
    ref(i, 0, n) ans += (p[i] != q[i]);
    cout << ans << '\n';
    return 0;
    // 10pts
}