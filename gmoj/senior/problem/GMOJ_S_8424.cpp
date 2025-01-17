#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 2e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, q;
int a[N];

struct trie_01
{
    int tr[N][2], scnt, ed[N], kl[N], len;
    void init()
    {
        scnt = 0;
        rep(i, 1, 100)
            ed[i] = -1;
        return;
    }
    void insert(int x, int iid)
    {
        rep(i, 1, 30)
            kl[i] = 0;
        len = 0;
        do
        {
            kl[++len] = x & 1;
            x >>= 1;
        } while (x);
        int st = 0;
        reb(i, 30, 1)
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
        reb(i, 30, 1)
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
        reb(i, 30, 1)
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
        rep(i, 1, 30)
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
} trie;
int f(int x, int nx, int ny) { return (x ^ nx) - ny; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    trie.init();
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        trie.insert(a[i], i);
    }
    for (int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        int l = trie.find(x, 0), r = trie.find(x, 1), res = -1;
        if (l > r)
            swap(l, r);
        if (f(a[l], x, y) * f(a[r], x, y) > 0)
        {
            puts("-1");
            continue;
        }
        while (l + 1 < r)
        {
            int mid = (l + r) >> 1;
            if (f(a[l], x, y) * f(a[mid], x, y) <= 0)
                r = mid;
            else
                l = mid;
        }
        cout << l << '\n';
    }
    return 0;
}