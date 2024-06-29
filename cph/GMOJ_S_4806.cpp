#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e6 + 7;

int n;
int a[N];
int f[N];
int mx[N];
int ans = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        mx[i] = max(mx[i - 1], a[i]);
    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j; j--)
            f[j] = ((ll)f[j] * j % MOD + f[j - 1]) % MOD;
        f[mx[i - 1]] = (f[mx[i - 1]] + a[i] - 1) % MOD;
    }
    for (int i = 1; i <= n; i++)
        ans = (ans + f[i]) % MOD;
    cout << ans << '\n';
    return 0;
}