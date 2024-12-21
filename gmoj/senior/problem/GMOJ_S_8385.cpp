#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
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

const int N = 2e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int qpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int fac[N + 5];
void factorial(int n)
{
    fac[0] = 1;
    ref(i, 1, n + 1)
    {
        fac[i] = fac[i - 1] * i % MOD;
    }
}

int solve(int n, int m)
{
    return (n >= m) ? fac[n] * qpow(fac[m], MOD - 2) % MOD * qpow(fac[n - m], MOD - 2) % MOD : 0;
}

int T;
int n, m;
int ans;
int k;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial(1e6);
    // cin >> T;
    read(T);
    while (T--)
    {
        // cin >> n >> m;
        read(n), read(m);
        k = n / m;
        ans = 0;
        rep(i, 1, k)
        {
            ans = (ans + (solve(n - i * m + 2 * i, 2 * i) - solve(n - i * m + i, 2 * i)) % MOD) % MOD;
            ans = (ans + MOD) % MOD;
            // cout << ans << ' ';
        }
        // cout << ans << '\n';
        write(ans);
        putchar('\n');
    }
    return 0;
}