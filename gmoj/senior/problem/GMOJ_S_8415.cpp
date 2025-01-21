#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 305;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int q;
int u[N], v[N];
int w[N][N];
int a, b, c, d;

int f[N][N][N][2];
int g[N][N][N];

signed main()
{
    // memset(f, 0x80, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n) cin >> u[i];
    rep(i, 1, n) cin >> v[i];
    rep(i, 1, n) rep(j, 1, n) cin >> w[i][j];
    rep(i, 1, n) rep(j, i, n) f[i][j][0][1] = -v[j];
    rep(i, 1, n) rep(j, i, n) rep(k, 1, n)
    {
        f[i][j][k][0] = f[i][j][k][1] = -INF;
        f[i][j][k][0] = max(f[i][j][k][0], max(f[i][j - 1][k][0], f[i][j - 1][k][1]));
        (f[i][j][k][1] < max(f[i][j - 1][k - 1][0], f[i][j - 1][k - 1][1])) && (g[i][j][k] = (f[i][j - 1][k - 1][0] < f[i][j - 1][k - 1][1] ? g[i][j - 2][k - 1] : g[i][j - 1][k - 1]) + v[j]);
        f[i][j][k][1] = max(f[i][j][k][1], max(f[i][j - 1][k - 1][0], f[i][j - 1][k - 1][1]) - v[j]);
        // f[i][j][k][0]
        f[i][j][k][0] = max(f[i][j][k][0], f[i][j][k - 1][0]);
        f[i][j][k][0] = max(f[i][j][k][0], max(f[i][j - 1][k - 1][0], f[i][j - 1][k - 1][1]));
        // f[i][j][k][1]
        f[i][j][k][1] = max(f[i][j][k][1], max(f[i][j][k - 1][1], f[i][j][k - 1][1] - u[k] + w[k][j]));
        cout << i << ' ' << j << ' ' << k << ' ' << f[i][j][k][0] << ' ' << f[i][j][k][1] << '\n';
    }
    while (q--)
    {
        cin >> a >> b >> c >> d;
        cout << max(f[c][d][b][0], f[c][d][b][1]) - max(f[c][d][a - 1][0], f[c][d][a - 1][1]) - g[c][d][a - 1] << '\n';
    }
    fprintf(stderr, "#%.3lf\n", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}