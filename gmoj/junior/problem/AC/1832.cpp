#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define en st + l
using namespace std;
typedef __int128 ll;

int n, m;
int a[85][85];

ll f[85][85];
ll ans;

void tpt(ll s)
{
    if (s > 9)
        tpt(s / 10);
    printf("%d", int(s % 10));
}
__int128 pw(int a, int b)
{
    __int128 ret = 1;
    while (b--)
        ret *= a;
    return ret;
}

int main()
{
    fre(ans);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int l = m; l >= 0; l--)
            for (int st = 1; st + l <= m + 1; st++)
                f[st][st + l - 1] = max(f[st - 1][st + l - 1] + a[i][st - 1] * pw(2, m - l),
                                        f[st][st + l] + a[i][st + l] * pw(2, m - l));
        ll mx = 0;
        for (int j = 1; j <= m; j++)
            mx = max(mx, f[j][j - 1]);
        ans += mx;
    }
    tpt(ans);
    return 0;
}