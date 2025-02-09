#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
string s;
ll f[N][2][2][2][2][2][2];

ll dfs(int now, int a, int b, int c, int x, int y, int z)
{
    // cout << now << ' ' << a << ' ' << b << ' ' << c << ' ' << x << ' ' << y << ' ' << z << '\n';
    if (now > n)
        return x && y && z;
    if (f[now][a][b][c][x][y][z] != -1)
        return f[now][a][b][c][x][y][z];
    ll res = 0;
    rep(c1, 0, (a ? s[now - 1] - '0' : 1)) rep(c2, 0, (b ? s[now - 1] - '0' : 1)) rep(c3, 0, (c ? s[now - 1] - '0' : 1))
    {
        int t1 = a & (c1 == s[now - 1] - '0'), t2 = b & (c2 == s[now - 1] - '0'), t3 = c & (c3 == s[now - 1] - '0');
        int tmp1 = x | ((c1 ^ c2) + (c1 ^ c3) > (c2 ^ c3));
        int tmp2 = y | ((c1 ^ c2) + (c2 ^ c3) > (c1 ^ c3));
        int tmp3 = z | ((c1 ^ c3) + (c2 ^ c3) > (c1 ^ c2));
        (res += dfs(now + 1, t1, t2, t3, tmp1, tmp2, tmp3)) %= MOD;
    }
    return f[now][a][b][c][x][y][z] = res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    n = s.length();
    memset(f, -1, sizeof(f));
    cout << dfs(1, 1, 1, 1, 0, 0, 0) << '\n';
    return 0;
}