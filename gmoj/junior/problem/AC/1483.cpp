#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

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

int n, m;
int v[65], w[65], q[65];
int f[65][3205];
int ans[3205];

void dp()
{
    for (int i = 1; i <= m; i++)
    {
        if (q[i] == 0)
        {
            int a[2], cnt = 0;
            for (int k = 1; k <= m; k++)
                if (q[k] == i)
                    a[cnt++] = k;
            for (int j = n; j >= v[i]; j--)
                f[i][j] = v[i] * w[i], ans[j] = max(ans[j], ans[j - v[i]] + f[i][j]);
            if (cnt)
                for (int k = 0; k < cnt; k++)
                    for (int j = n; j >= v[i] + v[a[k]]; j--)
                        f[i][j] = max(f[i][j], f[i][j - v[a[k]]] + v[a[k]] * w[a[k]]), ans[j] = max(ans[j], ans[j - v[i] - v[a[k]]] + f[i][j]);
            if (cnt == 2)
                for (int j = n; j >= v[i] + v[a[0]] + v[a[1]]; j--)
                    f[i][j] = max(f[i][j], f[i][j - v[a[0]] - v[a[1]]] + v[a[0]] * w[a[0]] + v[a[1]] * w[a[1]]), ans[j] = max(ans[j], ans[j - v[a[0]] - v[a[1]]] + f[i][j]);
        }
    }
}

int main()
{
    fre(ans);
    read(n), read(m);
    n /= 10;
    for (int i = 1; i <= m; i++)
    {
        read(v[i]), read(w[i]), read(q[i]);
        v[i] /= 10;
    }
    dp();
    printf("%d", ans[n] * 10);
    return 0;
}