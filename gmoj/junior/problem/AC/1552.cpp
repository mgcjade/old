#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;
const int MOD = 10000;

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

struct gj
{
    int a[1005] = {0, 1, 0}, len = 1;
};
gj _max(gj a, gj b)
{
    if (a.len == b.len)
    {
        for (int i = a.len; i; i--)
            if (a.a[i] != b.a[i])
                return a.a[i] < b.a[i] ? b : a;
        return a;
    }
    return a.len < b.len ? b : a;
}
gj _times(gj a, int b)
{
    for (int i = 1; i <= a.len; i++)
        a.a[i] *= b;
    a.len += 2;
    for (int i = 1; i <= a.len; i++)
        a.a[i + 1] += a.a[i] / MOD, a.a[i] %= MOD;
    while (a.a[a.len] == 0)
        a.len--;
    return a;
}
gj _divi(gj a, int b)
{
    gj ret;
    ret.len = a.len;
    ret.a[1] = 0;
    for (int i = a.len; i; i--)
    {
        ret.a[i] = a.a[i] / b, a.a[i - 1] += (a.a[i] % b) * MOD;
    }
    while (ret.a[ret.len] == 0 && ret.len)
        ret.len--;
    return ret;
}
void _write(gj s)
{
    printf("%d", s.a[s.len]);
    for (int i = s.len - 1; i; i--)
        printf("%04d", s.a[i]);
}

ll n;
struct node
{
    ll a, b;
};
node a[1005];
gj pro, ans;

bool cmp(node x, node y) { return x.a * x.b < y.a * y.b; }
void Sort(ll h, ll r)
{
    ll i = h, j = r;
    node mid = a[(i + j) >> 1];
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

signed main()
{
    ans.a[1] = 0;
    fre(ans);
    read(n);
    for (ll i = 0; i <= n; i++)
        read(a[i].a), read(a[i].b);
    Sort(1, n);
    for (ll i = 1; i <= n; i++)
    {
        pro = _times(pro, a[i - 1].a);
        ans = _max(ans, _divi(pro, a[i].b));
    }
    _write(ans);
    return 0;
}