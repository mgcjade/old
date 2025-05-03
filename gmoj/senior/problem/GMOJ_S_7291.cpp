#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 3e5;
const int M = 20;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, k;
int ans;
int sum, num, cnt, tot;
int head[N], dis[N];
int vis[N], wis[N], f[N];
mt19937 rnd(time(0));

struct SegmentTree
{
    int v[N];
    struct node
    {
        int l, r, ans;
    } T[N << 2];
    void build(int now, int l, int r)
    {
        T[now].l = l, T[now].r = r;
        if (l == r)
        {
            T[now].ans = v[dis[l]];
            return;
        }
        build((now << 1), l, ((l + r) >> 1)), build(((now << 1) | 1), ((l + r) >> 1) + 1, r);
        T[now].ans = T[(now << 1)].ans + T[((now << 1) | 1)].ans;
    }
    void change(int now, int l, int r, int x, int y)
    {
        if (l == r)
        {
            T[now].ans = y;
            return;
        }
        if (((l + r) >> 1) >= x)
            change((now << 1), l, ((l + r) >> 1), x, y);
        if (((l + r) >> 1) < x)
            change(((now << 1) | 1), ((l + r) >> 1) + 1, r, x, y);
        T[now].ans = T[(now << 1)].ans + T[((now << 1) | 1)].ans;
    }
    int query(int now, int l, int r, int x, int y)
    {
        if (x <= l && r <= y)
            return T[now].ans;
        int xx = 0;
        if (((l + r) >> 1) >= x)
            xx += query((now << 1), l, ((l + r) >> 1), x, y);
        if (((l + r) >> 1) < y)
            xx += query(((now << 1) | 1), ((l + r) >> 1) + 1, r, x, y);
        return xx;
    }
} V[M + 1];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> k;
    int op;
    rep(i, 1, m) rep(j, 1, M) V[j].v[i] = rnd() % k;
    rep(i, 1, n) cin >> dis[i];
    rep(j, 1, M) V[j].build(1, 1, n);
    int _Tp;
    cin >> _Tp;
    while (_Tp--)
    {
        cin >> op;
        int x, y, z;
        if (op == 1)
        {
            cin >> x >> y;
            rep(j, 1, M) V[j].change(1, 1, n, x, V[j].v[y]);
        }
        else
        {
            cin >> z;
            ans = 0;
            rep(j, 1, M) wis[j] = 0;
            for (int i = 1; i <= z; i++)
            {
                cin >> x >> y;
                rep(j, 1, M) wis[j] += V[j].query(1, 1, n, x, y);
            }
            int flag = 1;
            rep(j, 1, M) if (wis[j] % k != 0) flag = 0;
            cout << flag << '\n';
        }
    }
    return 0;
}