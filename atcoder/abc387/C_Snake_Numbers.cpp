#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int a[N], res, b[N];
string s, t;
int f[20][20];

int dfs(int x, int y, int z, int t)
{
    if (x > y)
        return 1;
    if (f[x][z])
        return f[x][z];
    for (int i = 0; i <= (z ? a[x] : 9) && i < t; i++)
        f[x][z] += dfs(x + 1, y, z & (i == a[x]), t);
    return f[x][z];
}
int solve(int n)
{
    memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b));
    int cnt = 0, t = n, res = 0;
    while (t)
        b[++cnt] = t % 10, t /= 10;
    rep(i, 1, cnt)
        a[i] = b[cnt - i + 1];
    rep(i, 2, cnt)
    {
        if (i == cnt)
        {
            rep(j, 1, a[1])
            {
                memset(f, 0, sizeof f);
                res += dfs(2, i, j == a[1], j);
            }
        }
        else
        {
            rep(j, 1, 9)
            {
                res += dfs(2, i, 0, j);
                memset(f, 0, sizeof(f));
            }
        }
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    cout << solve(b) - solve(a - 1);
    return 0;
}