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

int n;
int p[N], q[N];
int a[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> p[i];
    rep(i, 1, n) cin >> q[i];
    rep(i, 1, n) a[q[i]] = p[i];
    // rep(i, 1, n) cout << a[i] << ' ';
    // cout << '\n';
    rep(i, 1, n) cout << q[a[i]] << ' ';
    cout << '\n';
    return 0;
}