#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

const int N = 1.6e7 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, q, a[N];

struct Trie
{
    int tr[N][2], scnt, ed[N], kl[N], len;
    void init()
    {
        scnt = 0;
        for (int i = 1; i <= 100; i++)
            ed[i] = -1;
        return;
    }
    void insert(int x, int iid)
    {
        for (int i = 1; i <= 30; i++)
            kl[i] = 0;
        len = 0;
        do
        {
            kl[++len] = x & 1;
            x >>= 1;
        } while (x);
        int st = 0;
        for (int i = 30; i >= 1; i--)
        {
            if (!tr[st][kl[i]])
                tr[st][kl[i]] = ++scnt;
            st = tr[st][kl[i]];
        }
        ed[st] = iid;
        return;
    }
    int Fa()
    {
        int pos = 0;
        for (int i = 30; i >= 1; i--)
        {
            int opt = (!kl[i]);
            if (tr[pos][opt])
                pos = tr[pos][opt];
            else
                pos = tr[pos][!opt];
        }
        return ed[pos];
    }
    int Fi()
    {
        int pos = 0;
        for (int i = 30; i >= 1; i--)
        {
            int opt = (kl[i]);
            if (tr[pos][opt])
                pos = tr[pos][opt];
            else
                pos = tr[pos][!opt];
        }
        return ed[pos];
    }
    int find(int x, int opt)
    {
        int res = 0;
        len = 0;
        for (int i = 1; i <= 30; i++)
            kl[i] = 0;
        do
        {
            kl[++len] = x & 1;
            x >>= 1;
        } while (x);
        if (opt == 0)
            return Fa();
        else
            return Fi();
        return res;
    }
} T;
long long f(int x, int xx, int yy) { return 1ll * (x ^ xx) - 1ll * yy; }
signed main()
{
    scanf("%d%d", &n, &q);
    T.init();
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        T.insert(a[i], i);
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int l = T.find(x, 0), r = T.find(x, 1), res = -1;
        if (l > r)
            swap(l, r);

        if (1ll * f(a[l], x, y) * f(a[r], x, y) > 0ll)
        {
            puts("-1");
            continue;
        }
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (1ll * f(a[l], x, y) * f(a[mid], x, y) <= 0ll)
                r = mid;
            else
                l = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}