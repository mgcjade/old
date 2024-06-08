#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const __int128 MOD = 998244353;

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

__int128 n;
__int128 q = 1;
__int128 ans;

__int128 fastpow(__int128 a, __int128 b)
{
    __int128 res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int main()
{
    read(n);
    __int128 t = n;
    while (t)
    {
        t /= 10;
        q *= 10;
    }
    ans = (1 - fastpow(q, n)) * fastpow((1 - q), MOD - 2) % MOD * n % MOD;
    write(ans);
    return 0;
}