#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

ll a, m, l, r;

int main()
{
    cin >> a >> m >> l >> r;
    a -= l, r -= l, l -= l;
    a = (a % m + m) % m;
    ll ans = 0;
    if (r >= a)
        ans = (r - a) / m + 1;
    cout << ans;
    return 0;
}