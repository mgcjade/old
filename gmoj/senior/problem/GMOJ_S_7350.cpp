#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e2 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, q;
ll f[N][N];
ll x, y, z;
int l1, r1, l2, r2;
ll ans;

int main()
{
    // freopen("wanted.in", "r", stdin);
    // freopen("wanted.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(f, 0x3f, sizeof(f));
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y >> z;
        f[x][y] = min(f[x][y], z);
        f[y][x] = min(f[y][x], z);
    }
    // floyd
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    while (q--)
    {
        cin >> l1 >> r1 >> l2 >> r2;
        ans = 0;
        for (int i = l1; i <= r1; i++)
            for (int j = l2; j <= r2; j++)
                ans = max(ans, f[i][j]);
        cout << ans << '\n';
    }
    return 0;
}