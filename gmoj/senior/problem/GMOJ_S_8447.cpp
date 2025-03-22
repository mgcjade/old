#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 3e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int pos[N], add[N];
int vis[N];
int ans[N][N], sum, cnt;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i], pos[a[i]] = i;
    rep(i, 1, n) add[i] = add[i - 1] + (pos[i - 1] > pos[i]);
    cout << (sum = __lg(add[n]) + 1) << '\n';
    rep(i, 1, n) cout << a[i] << " \n"[i == n];
    // cerr << add[n] << '\n';
    rep(i, 1, sum)
    {
        cnt = 0;
        rep(j, 1, n) if (((add[j] >> i - 1) & 1) == 0) ans[i][++cnt] = pos[j], vis[a[pos[j]]] = 1;
        sort(ans[i] + 1, ans[i] + cnt + 1);
        rep(j, 1, cnt) ans[i][j] = a[ans[i][j]];
        rep(j, 1, n) if (!vis[a[j]]) ans[i][++cnt] = a[j];
        rep(j, 1, n) cout << ans[i][j] << " \n"[j == n], vis[ans[i][j]] = 0, a[j] = ans[i][j], pos[a[j]] = j;
    }

    return 0;
}