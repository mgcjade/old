#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

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

int n, k, p;
ll ans;
struct node
{
    int clr, num, pay;
};
node a[N];
int mn[N][20];

void _read()
{
    read(n), read(k), read(p);
    for (int i = 1; i <= n; i++)
    {
        read(a[i].clr), read(a[i].pay);
        a[i].num = i;
    }
}
void _init()
{
    // 倍增
    int x = log2(n);
    memset(mn, 0x3f, sizeof(mn));
    for (int i = 1; i <= n; i++)
        mn[i][0] = a[i].pay;
    for (int j = 1; j <= x; j++)
    {
        int s = pow(2, j - 1);
        for (int i = 1; i <= n; i++)
            mn[i][j] = min(mn[i][j - 1], mn[i + s][j - 1]);
    }
}
bool _cmp(node x, node y) { return x.clr == y.clr ? x.num < y.num : x.clr < y.clr; }
void _sort(int h, int r)
{
    int i = h, j = r;
    node mid = a[(h + r) >> 1];
    while (i <= j)
    {
        while (_cmp(a[i], mid))
            i++;
        while (_cmp(mid, a[j]))
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        _sort(h, j);
    if (i < r)
        _sort(i, r);
}
int _min(int x, int y)
{
    int s = log2(y - x + 1);
    return min(mn[x][s], mn[y - (1 << s) + 1][s]);
}
void _count()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; a[i].clr == a[j].clr && j <= n; j++)
            if (_min(a[i].num, a[j].num) <= p)
                ans++;
}
void _output()
{
    printf("%lld", ans);
}

int main()
{
    fre(ans);
    _read();
    _init();
    _sort(1, n);
    _count();
    _output();
    return 0;
}
