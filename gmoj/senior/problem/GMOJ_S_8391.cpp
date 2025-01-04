#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline int lowbit(int x) { return x & -x; }

int n, m;
int w[N][N], c[N][N];
int f[1 << N][N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m) cin >> w[i][j];
    rep(i, 1, n) rep(j, 1, m) cin >> c[i][j];
    int s = 1 << n;
    memset(f, 0x3f, sizeof(f));
    rep(i, 1, n) f[1 << i - 1][i] = 0;
    ref(i, 1, s)
    {
        if ((i ^ lowbit(i)) == 0)
            continue;
        rep(j, 1, n)
        {
            int x = i ^ (1 << j - 1), y = i & (1 << j - 1);
            if (x == 0 || y == 0)
                continue;
            rep(k, 1, n)
            {
                if (x & (1 << k - 1))
                {
                    f[i][j] = min(f[i][j], f[x][k] + w[k][j]);
                }
            }
        }
    }
    ref(i, 1, s)
    {
        rep(j, 1, n) cout << f[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}