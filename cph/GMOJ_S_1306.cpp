#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
ll p;
int a[N];
ll sum;
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k >> p;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = INF;
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum += a[j];
            if (sum % p >= k)
                ans = min(ans, sum % p);
        }
    }
    cout << ans << '\n';
    return 0;
}