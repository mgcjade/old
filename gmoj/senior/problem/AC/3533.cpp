#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int MOD = 1e8 - 3;

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
int tre[100005];
int ans;
struct node
{
    int a, b;
};
node a[100005], b[100005];
int t[100005];
bool cmp(node x, node y) { return x.a < y.a; }
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
void _sort(int h, int r)
{
    int i = h, j = r;
    node mid = b[(h + r) >> 1];
    while (i <= j)
    {
        while (cmp(b[i], mid))
            i++;
        while (cmp(mid, b[j]))
            j--;
        if (i <= j)
        {
            swap(b[i], b[j]);
            i++, j--;
        }
    }
    if (h < j)
        _sort(h, j);
    if (i < r)
        _sort(i, r);
}
int lowbit(int x) { return x & (-x); }
int _cnt(int i)
{
    int ret = 0;
    for (; i; i -= lowbit(i))
        ret += tre[i];
    return ret;
}
void _add(int i)
{
    for (; i <= n; i += lowbit(i))
        tre[i]++;
}

int main()
{
    fre(ans);
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i].a);
    for (int i = 1; i <= n; i++)
        read(b[i].a);
    for (int i = 1; i <= n; i++)
        a[i].b = b[i].b = i;
    Sort(1, n);
    _sort(1, n);
    for (int i = 1; i <= n; i++)
        t[a[i].b] = b[i].b;
    for (int i = 1; i <= n; i++)
    {
        _add(t[i]);
        ans += i - _cnt(t[i]);
        ans %= MOD;
    }
    printf("%d", ans);
    return 0;
}