#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

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

__int128 n;
__int128 a;

signed main()
{
    read(n);
    a = 1;
    for (int i = 1; a <= n; i++)
    {
        a = a * i;
        if (a == n)
        {
            printf("%d\n", i);
            return 0;
        }
        // printf("%d\n", i);
    }
    return 0;
}