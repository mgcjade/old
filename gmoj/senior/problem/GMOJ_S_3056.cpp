#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 999983;

int n;
int a[15];
string str;
int len, mx;
ll f[N][10 * N];
ll ans;
ll sum1, sum2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++)
    {
        a[i + 1] = str[i] - '0';
        mx = max(mx, a[i + 1]);
    }
    sort(a + 1, a + len + 1);
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= mx * n; j++)
            for (int k = 1; k <= len && a[k] <= j; k++)
                f[i][j] = (f[i][j] + f[i - 1][j - a[k]]) % MOD;
    for (int i = 0; i <= n * mx; i++)
    {
        sum1 = (sum1 + (f[n >> 1][i] * f[n >> 1][i]) % MOD) % MOD;
        sum2 = (sum2 + (f[n - (n >> 1)][i] * f[n - (n >> 1)][i]) % MOD) % MOD;
        ans = (ans + (2 * f[n][i] * f[n][i]) % MOD) % MOD;
    }
    ans = ((ans - sum1 * sum2) % MOD + MOD) % MOD;
    cout << ans << '\n';
    return 0;
}