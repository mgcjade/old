#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 755;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N][N];
int f[N][N];
int g[N][N];

int dp(int l, int m, int r)
{
    if (l >= m || m > r)
        return 0;
    return g[l][r] - g[l][m - 1] - g[m][r];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 2, n) ref(j, 1, i) cin >> a[i][j], a[j][i] = a[i][j];
    memset(f, 0x3f, sizeof(f));
    rep(i, 1, n) f[i][i] = 0;
    reb(i, n, 1) rep(j, i + 1, n)
    {
        g[i][j] = g[i + 1][j] + g[i][j - 1] - g[i + 1][j - 1] + max(-a[i][j], 0);
        ref(k, i, j) f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + max(0, a[i][k + 1]) + dp(i + 1, k + 1, j));
    }
    cout << f[1][n];
    return 0;
}