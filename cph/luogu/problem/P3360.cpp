#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int n;
ll k;
ll a[105][105];
ll ans[105][105];
ll t[105][105];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        ans[i][i] = 1;
    while (k)
    {
        if (k & 1)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                {
                    t[i][j] = 0;
                    for (int k = 1; k <= n; k++)
                        t[i][j] = (t[i][j] + ans[i][k] * a[k][j]) % MOD;
                }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    ans[i][j] = t[i][j];
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                t[i][j] = 0;
                for (int k = 1; k <= n; k++)
                    t[i][j] = (t[i][j] + a[i][k] * a[k][j]) % MOD;
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                a[i][j] = t[i][j];
        k >>= 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << ans[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}