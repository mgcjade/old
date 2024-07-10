#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, k;
ll l, r;
ll ans;

int main()
{
    cin >> n >> k;
    ans = n * k;
    for (l = 1; l <= n; l = r + 1)
    {
        r = n;
        if (k / l != 0)
            r = min(r, k / (k / l));
        ans -= (k / l) * (l + r) * (r - l + 1) / 2;
    }
    cout << ans << '\n';
    return 0;
}