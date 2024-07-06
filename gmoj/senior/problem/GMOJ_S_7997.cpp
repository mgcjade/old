#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n, m;
int a[N], da[N], f[N], sum[N], ff[(N + 5) << 1];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> da[i];
        a[da[i]]++;
    }
    for (int i = 1; i <= n + 1; i++)
        sum[i] = sum[i - 1] + a[i];
    // f[0] = 1, f[1] = 1;
    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] == 0)
    //         f[i + 1] = f[i - 1 + 1];
    //     if (sum[i] == i)
    //         f[i + 1]++;
    //     for (int j = 2; j <= i; j++)
    //         if (sum[i] - i - 1 == sum[j - 1] - j && a[j - 1] == 0)
    //             f[i+1] = (f[i+1] + f[j - 2+1]) % MOD;
    // }
    f[0] = 1, ff[N] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        if (a[i])
            continue;
        int j = sum[i] - i + 1 + N;
        f[i] = (f[i] + ff[j]) % MOD;
        ff[j - 1] = (ff[j - 1] + f[i]) % MOD;
    }
    // for (int i = -n; i <= n; i++)
    //     cout << i << " " << ff[i + n] << '\n';
    // for (int i = 1; i <= n; i++)
    //     cout << f[i + 1] << " ";
    // cout << f[n] << '\n';
    cout << f[n + 1] << '\n';
    return 0;
}