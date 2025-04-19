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

int T;
int n, m;
int a[N], b[N], c[N];

vector<vector<double>> x;

double dp(int u, int v)
{
    if (x[u][v] != -1)
        return x[u][v];
    double mx = 0;
    ref(i, 0, n) if (!(v & (1 << i)) && u >= b[i]) mx = max(mx, (c[i] / 100.0) * (a[i] + dp(u - b[i], v | (1 << i))) + (1 - c[i] / 100.0) * dp(u - b[i], v));
    return x[u][v] = mx;
}
signed main()
{
    cin >> n >> m;
    ref(i, 0, n) cin >> a[i] >> b[i] >> c[i];
    x.assign(m + 1, vector<double>(1 << n, -1));
    cout << fixed << setprecision(8) << dp(m, 0) << endl;
    return 0;
}