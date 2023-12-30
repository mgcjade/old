#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;

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

int n;
int h[N];
int f[N][2];
int ans;

int main()
{
    fre(ans);
    read(n);
    for (int i = 1; i <= n; i++)
        read(h[i]);
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = f[i - 1][0], f[i][1] = f[i - 1][1];
        if (h[i - 1] > h[i])
            f[i][0] = max(f[i - 1][1] + 1, f[i][0]);
        if (h[i - 1] < h[i])
            f[i][1] = max(f[i - 1][0] + 1, f[i][1]);
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, max(f[i][0], f[i][1]));
    printf("%d", ans);
    return 0;
}