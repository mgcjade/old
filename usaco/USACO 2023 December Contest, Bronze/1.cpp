#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

inline void read(ll &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

ll n, m, t;
ll cow[N], candy[N], c[N];

int main()
{
    fre(ans);
    read(n), read(m);
    for (int i = 0; i < n; i++)
        read(cow[i]);
    for (int j = 0; j < m; j++)
        read(candy[j]);
    for (int j = 0; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            t = min(cow[i], candy[j]) - c[j];
            if (t <= 0)
                continue;
            cow[i] += t;
            c[j] += t;
            if (c[j] == candy[j])
                break;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%lld\n", cow[i]);
    return 0;
}