#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 105;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n, k;
int m;
int d[N][N];
int flag;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        m = n * (n - 1) / 2, flag = 1;
        rep(i, 1, n) rep(j, 1, n) cin >> d[i][j];
        rep(i, 1, n) if (d[i][i] != 0) flag = 0;
        rep(i, 1, n) rep(j, i + 1, n) if (d[i][j] != d[j][i]) flag = 0;
        if (!flag)
        {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        cout << m << '\n';
        rep(i, 1, n) rep(j, i + 1, n) cout << i << ' ' << j << ' ' << d[i][j] + k << '\n';
    }
    return 0;
}