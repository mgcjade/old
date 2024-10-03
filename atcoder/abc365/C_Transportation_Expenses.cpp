#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, m;
ll a[N];
ll sum;
ll l, r;

bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += min(a[i], x);
        if (cnt > m)
            return 0;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= m)
    {
        cout << "infinite";
        return 0;
    }
    l = 1, r = m;
    ll mid;
    while (l <= r)
    {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << l - 1;
    return 0;
}