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

int n, m, k;
int f[1005][3];
struct node
{
    int p, l, h;
};
node a[10005];
bool cmp(node x, node y) { return x.p < y.p; }
void Sort(int h, int r)
{
    int i = h, j = r;
    node mid = a[(h + r) >> 1];
    while (i <= j)
    {
        while (cmp(a[i], mid))
            i++;
        while (cmp(mid, a[j]))
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        Sort(h, j);
    if (i < r)
        Sort(i, r);
}
int x[10005], y[10005];

int main()
{
    fre(ans);
    read(n), read(m), read(k);
    for (int i = 1; i <= n; i++)
        read(x[i - 1]), read(y[i - 1]);
    for (int i = 1; i <= k; i++)
        read(a[i].p), read(a[i].l), read(a[i].h);
    Sort(1, k);
    a[0].h = m + 1;
    int cnt = 1, t;
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[cnt].p == i)
            t = cnt, cnt++;
        else
            t = 0;
        for (int j = 1; j <= m; j++)
        {
        }
        for (int j = 1; j <= m; j++)
            if (f[j][i & 1] != INF)
                mx = i;
        if (mx < i)
            break;
    }
    if (mx == n)
    {
        int mn = INF;
        for (int i = 1; i <= m; i++)
            mn = min(mn, f[i][n & 1]);
        printf("1\n%d", mn);
    }
    else
        printf("0\n%d", cnt - 2);
    return 0;
}