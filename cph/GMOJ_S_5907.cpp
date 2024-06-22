#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 505;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k, w;
int q;
int x, y;
ll a[N], v[N];
bool u[N][N];
ll f[N][N];
ll ans = INF;

bool check(int l, int r, int j)
{
    for (int i = l; i <= r; i++)
        if (u[i][j])
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // fre(qinggong);
    memset(f, 0x3f, sizeof(f));
    cin >> n >> k >> w;
    for (int i = 1; i <= k; i++)
        f[0][i] = 0;
    for (int i = 1; i <= k; i++)
        cin >> a[i] >> v[i];
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x >> y;
        u[x][y] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - a[j] >= 0 && check(i - a[j] + 1, i, j))
                for (int h = 1; h <= k; h++)
                {
                    f[i][j] = min(f[i][j], f[i - a[j]][h] + w * (j != h) + v[j]);
                }
            // cout << f[i][j] << ' ';
        }
        // cout << '\n';
    }
    for (int i = 1; i <= k; i++)
        ans = min(ans, f[n][i]);
    if (ans == INF)
        cout << "-1";
    else
        cout << ans << '\n';
    return 0;
}