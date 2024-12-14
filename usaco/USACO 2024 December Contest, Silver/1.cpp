#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n;
ll a[N];
ll sum[N];
ll ans;
int k;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            sum[i] = sum[i - 1] + a[i];
        k = n / 2 - 1;
        for (int i = 0; i <= k; i++)
            ans = max(ans, sum[i] + (sum[n] - sum[n - (k - i)]));
        cout << sum[n] - ans << ' ' << ans << '\n';
    }
    return 0;
}