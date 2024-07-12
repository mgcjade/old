#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
struct tree
{
    int lson, rson;
    int l, r;
    int val;
} t[25000000];
int tot;
int a[N];
int root[N], cnt;

int build(int l, int r)
{
    int node = ++tot;
    t[node].l = l, t[node].r = r;
    if (l == r)
    {
        t[node].val = a[l];
        return node;
    }
    int mid = (l + r) >> 1;
    t[node].lson = build(l, mid);
    t[node].rson = build(mid + 1, r);
    return node;
}
int clone(int k)
{
    t[++tot] = t[k];
    return tot;
}
int change(int k, int l, int val)
{
    int node = clone(k);
    if (t[node].l == t[node].r)
    {
        t[node].val = val;
        return node;
    }
    int mid = (t[node].l + t[node].r) >> 1;
    if (l <= mid)
        t[node].lson = change(t[k].lson, l, val);
    else
        t[node].rson = change(t[k].rson, l, val);
    return node;
}
int query(int k, int l)
{
    if (t[k].l == t[k].r)
        return t[k].val;
    int mid = (t[k].l + t[k].r) >> 1;
    if (l <= mid)
        return query(t[k].lson, l);
    else
        return query(t[k].rson, l);
}

int flag, v, l, val;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    root[0] = build(1, n);
    while (m--)
    {
        cin >> v >> flag >> l;
        if (flag == 1)
        {
            cin >> val;
            root[++cnt] = change(root[v], l, val);
        }
        else
        {
            root[++cnt] = root[v];
            cout << query(root[v], l) << '\n';
        }
    }
    // for (int i = 1; i <= tot; i++)
    //     cout << t[i].l << ' ' << t[i].r << ' ' << t[i].lson << ' ' << t[i].rson << t[i].val << '\n';
    return 0;
}