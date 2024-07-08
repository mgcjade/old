#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 3e5 + 5;
const double INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, q;
struct node
{
    int num, a;
} a[N];
bool cmp(node x, node y) { return x.a > y.a; }

int x, y;
struct edge
{
    int to, nxt;
};
edge e[N << 1];
int hd[N], tot;
void add(int u, int v)
{
    e[++tot] = {v, hd[u]};
    hd[u] = tot;
}

struct search
{
    int num, dis = 1;
} pre[N];
int fnd(int t)
{
    if (pre[t].num == t)
        return pre[t].num;
    return pre[t].num = fnd(pre[t].num);
}

struct convex
{
    double l, r;
    int a, k;
};
convex con[N];
int cnt;
bool cmpp(convex x, convex y) { return x.a == y.a ? x.k < y.k : x.a < y.a; }

int st[N], h;
double jd(convex x, convex y) { return x.a == y.a ? x.r : (y.k - x.k) / 1.0 / (x.a - y.a); }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].a;
        a[i].num = i;
        pre[i].num = i;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }

    sort(a + 1, a + n + 1, cmp);
    con[++cnt] = {-INF, INF, 1, a[1].a};
    for (int i = 1; i <= n; i++)
    {
        x = fnd(a[i].num);
        for (int j = hd[i]; j; j = e[j].nxt)
        {
            if (a[e[j].to].a < a[i].a)
                continue;
            y = fnd(e[j].to);
            if (x != y)
            {
                pre[y].num = x;
                pre[x].dis = pre[y].dis + pre[x].dis;
                con[++cnt] = {-INF, INF, pre[x].dis, a[i].a * pre[x].dis};
            }
        }
    }
    sort(con + 1, con + cnt + 1, cmpp);
    for (int i = 1; i <= cnt; i++)
        cout << con[i].a << ' ' << con[i].k << '\n';

    st[++h] = 1;
    for (int i = 2; i <= cnt; i++)
    {
        double d = jd(con[st[h]], con[i]);
        while (h > 0 && (con[i].a == con[st[h]].a || d <= con[st[h]].l))
        {
            h--;
            d = jd(con[st[h]], con[i]);
        }
        if (h == 0)
            st[++h] = i;
        else if (jd(con[st[h]], con[i]) > con[st[h]].l)
        {
            d = jd(con[st[h]], con[i]);
            con[st[h]].r = d;
            st[++h] = i;
            con[st[h]].l = d;
        }
    }
    for (int i = 1; i <= h; i++)
        cout << con[st[i]].a << ' ' << con[st[i]].k << ' ' << fixed << setprecision(0) << con[st[i]].l << ' ' << fixed << setprecision(0) << con[st[i]].r << '\n';

    int b, mid;
    while (q--)
    {
        cin >> b;
        x = 1, y = h;
        while (x <= y)
        {
            mid = (x + y) >> 1;
            if (con[st[mid]].l > b)
                y = mid - 1;
            else if (con[st[mid]].r < b)
                x = mid + 1;
            else
                break;
        }
        cout << con[st[mid]].k + con[st[mid]].a * b << '\n';
    }

    return 0;
}