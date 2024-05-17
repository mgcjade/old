#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef __int128 ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e8;

template <class _Tp>
void read(_Tp &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}
template <class _Tp>
void write(_Tp s)
{
    if (s < 0)
        putchar('-'), s = -s;
    _Tp y = 10;
    int len = 1;
    while (y <= s)
        y *= 10, len++;
    while (len--)
    {
        y /= 10;
        putchar(s / y + 48);
        s %= y;
    }
}

ll n;
ll a[N];
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    read(n);
    for (ll i = 1; i <= n; i++)
        read(a[i]);
    for (ll i = 1; i <= n; i++)
    {
        ans += a[i] * (n - i);
        ans += a[i] * (i - 1);
    }
    sort(a + 1, a + n + 1);
    ll j = n;
    for (ll i = 1; i <= n; i++)
    {
        j = max(j, i);
        while (j > i && a[i] + a[j] >= MOD)
            j--;
        ans -= (n - j) * MOD;
    }
    write(ans);
    return 0;
}