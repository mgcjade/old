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
int ans = INF;

int a[4][105][105];
int b[105][105];
string s;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> s;
        rep(j, 1, n) a[0][i][j] = s[j - 1] - '0';
    }
    rep(k, 1, 3) rep(i, 1, n) rep(j, 1, n) a[k][i][j] = a[k - 1][n - j + 1][i];
    rep(i, 1, n)
    {
        cin >> s;
        rep(j, 1, n) b[i][j] = s[j - 1] - '0';
    }
    int cnt;
    rep(k, 0, 3)
    {
        cnt = k;
        rep(i, 1, n) rep(j, 1, n) cnt += (a[k][i][j] != b[i][j]);
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}