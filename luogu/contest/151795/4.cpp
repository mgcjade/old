#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}

ll a, b, c, d, e, f, g;
int x1, x2, yy1, y2;
int MOD;

int F(ll x, ll y)
{
    return ((a * x % MOD * x % MOD * x % MOD) + (b * y % MOD * y % MOD * y % MOD) + (c * x % MOD * x % MOD * y % MOD) + (d * x % MOD * y % MOD * y % MOD) + (e * x % MOD * y % MOD) + (f * x % MOD) + (g * y % MOD)) % MOD;
}

int ans;

int main()
{
    scanf("%lld%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &e, &f, &g);
    scanf("%d", &MOD);
    scanf("%d%d%d%d", &x1, &x2, &yy1, &y2);
    for (int x = x1; x <= x2; x++)
        for (int y = yy1; y <= y2; y++)
            ans = max(ans, F(x, y));
    printf("%d", ans);
    return 0;
}