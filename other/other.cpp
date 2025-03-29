#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int ans;
int l, r, v;
int p[N];
signed main()
{
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> l >> r >> v;
        p[l] += v;
        if (r + 1 <= n)
            p[r + 1] -= v;
    }
    rep(i, 1, n) p[i] += p[i - 1];
    rep(i, 1, n) cerr << p[i] << ' ';
    rep(i, 1, n)
    {
        int k = 1;
        rep(j, i, n) ans += (k *= p[i]), k %= MOD, ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}