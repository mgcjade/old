#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll rt(ll n, ll d)
{
    ll ret = d;
    ret -= n * n;
    ret = min(ll(ret - ll(sqrt(ret)) * ll(sqrt(ret))), ll((ll(sqrt(ret)) + 1) * (ll(sqrt(ret)) + 1) - ret));
    return ret;
}

ll d, n, ans = 0x7f7f7f7f7f7f7f7f;

int main()
{
    scanf("%lld", &d);
    n = sqrt(d);
    for (ll i = 0; i <= n; i++)
    {
        ans = min(ans, rt(i, d));
    }
    printf("%lld", ans);

    return 0;
}