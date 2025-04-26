#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int __int128

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

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int _lcm(int a, int b)
{
    return a / __gcd(a, b) * b;
}

int l, t, v1, v2;
int v, w;
int ans;
void solve()
{
    read(l), read(v1), read(v2), read(t);
    if (v1 < v2)
        swap(v1, v2);
    v = v1 + v2, w = v1 - v2;
    ans = (v * t + l) / (2 * l);
    if (v2 != 0)
        ans += (w * t + l) / (2 * l);
    int lc = _lcm(v1 * l, v2 * l);
    // time = lc / v1 / v2;
    if (v2 != 0 && (lc / v2 - lc / v1) % (2 * l) == l)
    {
        ans -= (t * v1 * v2 + lc) / (2 * lc);
    }
    write(ans);
    putchar('\n');
    // cerr << (v * t + l) / (2 * l) << " " << (w * t + l) / (2 * l) << "\n";
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    read(T);
    while (T--)
        solve();
    return 0;
}