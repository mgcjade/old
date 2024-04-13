#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int n, t, ans = 0;
    cin >> n;
    while (--n)
    {
        cin >> t;
        ans -= t;
    }
    cout << ans << '\n';
    return 0;
}