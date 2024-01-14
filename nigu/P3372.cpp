#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline void read(ll &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}

ll n, m;
ll v[N];
ll t, x, y, z;
struct tree
{
    int st, en;
    int son[2];
    ll sum;
    ll lz;
};
tree a[N << 2];

void pushup(int k)
{
    a[k].sum = a[a[k].son[0]].sum + a[a[k].son[1]].sum;
}
void pushdown(int k)
{
    if (a[k].st != a[k].en)
        a[a[k].son[0]].lz += a[k].lz, a[a[k].son[1]].lz += a[k].lz;
    a[k].sum += a[k].lz * (a[k].en - a[k].st + 1), a[k].lz = 0;
}
void made(int k, int l, int r)
{
    a[k].st = l, a[k].en = r;
    if (a[k].st == a[k].en)
        a[k].sum = v[a[k].st];
    else
    {
        int mid = (a[k].st + a[k].en) >> 1;
        a[k].son[0] = k << 1, a[k].son[1] = (k << 1) + 1;
        made(k << 1, l, mid);
        made((k << 1) + 1, mid + 1, r);
        pushup(k);
    }
}
void add(int k, int l, int r, int ad)
{
    if (a[k].st >= l && a[k].en <= r)
    {
        a[k].lz += ad;
        return;
    }
    if (a[k].st > r || a[k].en < l)
        return;
    a[k].sum += ad * (min(r, a[k].en) - max(l, a[k].st) + 1);
    add(a[k].son[0], l, r, ad);
    add(a[k].son[1], l, r, ad);
}
ll count(int k, int l, int r)
{
    if (a[k].st > r || a[k].en < l)
        return 0;
    if (a[k].lz != 0)
        pushdown(k);
    if (a[k].st >= l && a[k].en <= r)
        return a[k].sum;
    return count(a[k].son[0], l, r) + count(a[k].son[1], l, r);
}

int main()
{
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(v[i]);
    made(1, 1, n);
    while (m--)
    {
        read(t);
        if (t == 1)
        {
            read(x), read(y), read(z);
            add(1, x, y, z);
        }
        else
        {
            read(x), read(y);
            ll ans = count(1, x, y);
            printf("%lld\n", ans);
        }
    }
    return 0;
}