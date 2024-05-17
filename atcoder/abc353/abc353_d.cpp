#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
ll a[N];
ll len[N];
ll ans;
ll sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i; i--)
    {
        len[i] = 1;
        ans = (ans + a[i] * sum % MOD + a[i] * (i - 1)) % MOD;
        while (a[i])
            a[i] /= 10, len[i] = len[i] * 10 % MOD;
        sum = (sum + len[i]) % MOD;
    }
    cout << ans << "\n";
    return 0;
}