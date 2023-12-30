#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

int n, m, s, l;
int a[105];

int main()
{
    memset(a, 0x3f, sizeof(a));
    a[0] = 0;
    read(n), read(m), read(s), read(l);
    for (int i = 1; i <= n; i++)
    {
        a[i] = min(a[i], a[max(0, i - 6)] + m);
        a[i] = min(a[i], a[max(0, i - 8)] + s);
        a[i] = min(a[i], a[max(0, i - 12)] + l);
    }
    printf("%d", a[n]);
    return 0;
}