#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, len;
double p;

string str[N];
int tre[N * N][3], cnt = 1;
void insert(string &s)
{
    int x = 1;
    ref(i, 0, len)
    {
        int c = s[i] - '0';
        if (!tre[x][c])
            tre[x][c] = ++cnt;
        tre[x = tre[x][c]][2]++;
    }
}

double f[N][N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> len >> p;
    p = max(p, 1 - p);
    rep(i, 1, n) cin >> str[i], insert(str[i]);
    f[0][0] = 1;
    int flag;
    rep(i, 0, n) rep(j, !i, n)
    {
        flag = (i > j);
        if (i)
            f[i][j] += f[i - 1][j] * max(flag * p, (!flag) * (1 - p));
        if (j)
            f[i][j] += f[i][j - 1] * max(flag * (1 - p), (!flag) * p);
        // cout << i << ' ' << j << ' ' << f[i][j] << '\n';
    }
    double ans = 1;
    rep(i, 1, cnt) ans *= f[tre[tre[i][1]][2]][tre[tre[i][0]][2]];
    cout << fixed << setprecision(12) << ans << '\n';
    // rep(i, 1, cnt) cout << tre[i][0] << ' ' << tre[i][1] << ' ' << tre[i][2] << '\n';
    fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}