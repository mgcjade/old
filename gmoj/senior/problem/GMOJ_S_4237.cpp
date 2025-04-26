#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int unsigned int

const int N = 1e5 + 5;

int n, T;
pair<int, int> v[N];

class segmentTree
{
private:
    struct node
    {
        int l, r, mn;
        array<int, 7> sum;
        node *ls = nullptr, *rs = nullptr;
    } t[N << 2];
    node INF = {0, 0, 0, {0}};

public:
    node *root = &t[1];
    void pushup(node *cur)
    {
        cur->mn = min(cur->ls->mn, cur->rs->mn);
        int mx = max(cur->ls->mn, cur->rs->mn);
        rep(i, 0, 6) rep(j, 0, 6 - i) if (i + j)
        {
            cur->sum[i + j] += cur->ls->sum[i] * cur->rs->sum[j];
            if (i)
                cur->sum[i + j] += cur->ls->sum[i - 1] * cur->rs->sum[j] * mx;
            if (j)
                cur->sum[i + j] += cur->ls->sum[i] * cur->rs->sum[j - 1] * mx;
        }
    }
    node match(node a, node b)
    {
        if (a.mn == 0)
            return b;
        if (b.mn == 0)
            return a;
        node c;
        c.ls = &a, c.rs = &b;
        pushup(&c);
        return c;
    }
    void build(node *cur, int l, int r)
    {
        cur->l = l, cur->r = r;
        if (l == r)
        {
            cur->mn = v[l].second;
            cur->sum[1] = v[l].second;
            return;
        }
        int mid = (l + r) >> 1;
        build(cur->ls = &t[cur->l = l], l, mid), build(cur->rs = &t[cur->r = mid + 1], mid + 1, r);
        pushup(cur);
    }
    node query(node *cur, int l, int r)
    {
        if (r < cur->l || cur->r < l)
            return INF;
        if (cur->l >= l && cur->r <= r)
            return *cur;
        node ret;
        if (cur->ls != nullptr)
        {
            ret = query(cur->ls, l, r);
            if (cur->rs != nullptr)
                ret = match(ret, query(cur->rs, l, r));
        }
        else if (cur->rs != nullptr)
            ret = query(cur->rs, l, r);
        return ret;
    }
    int getans(int l, int r, int x)
    {
        return query(root, l, r).sum[x];
    }
} s;

set<int> st;
map<int, int> mp;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> T;
    rep(i, 1, n) cin >> v[i].first;
    rep(i, 1, n) cin >> v[i].second;
    sort(v + 1, v + n + 1);
    rep(i, 1, n) mp[v[i].first] = i, st.insert(i);
    s.build(s.root, 1, n);
    while (T--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        cout << s.getans(mp[*st.lower_bound(l)], mp[*(st.upper_bound(r + 1)--)], x) << '\n';
    }
    return 0;
}