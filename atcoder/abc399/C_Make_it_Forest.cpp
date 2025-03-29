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

int n, m;
int u, v;
int pre[N];
int fnd(int t) { return pre[t] = (pre[t] == t ? t : fnd(pre[t])); }
int ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) pre[i] = i;
    while (m--)
    {
        cin >> u >> v;
        int x = fnd(u), y = fnd(v);
        if (x != y)
            pre[x] = y;
        else
            ans++;
    }
    cout << ans << '\n';
    return 0;
}