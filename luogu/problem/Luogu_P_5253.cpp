#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n;
ll cnt;
ll ans = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt = 0;
            while (n % i == 0)
                n /= i, cnt++;
            ans *= (2 * cnt + 1);
        }
    }
    if (n > 1)
        ans *= 2 + 1;
    cout << ans / 2 + 1 << '\n';
    return 0;
}