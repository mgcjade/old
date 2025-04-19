#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "v", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 1e8 + 7;
const int MOD = 998244353;

int T;
int n, m, q;
int ans;
int vis[N];
int hd[N], to[N], nxt[N];
int Tp, p[66] = {1};
int cnt, flag;

char ch[N];
string s;

struct node
{
    int w, v;
} a[N];

void init()
{
    rep(i, 0, 63) a[i] = {0, 0};
    flag = cnt = 0;
}
void add(int x, int y) { nxt[++Tp] = hd[x], to[Tp] = y, hd[x] = Tp; }
void insert(int x, int g)
{
    if (flag)
        return;
    reb(i, 62, 0) if (x & (1ll << i))
    {
        if (!a[i].w)
        {
            a[i] = {x, g}, ++cnt;
            return;
        }
        else
            x ^= a[i].w, g ^= a[i].v;
    }
    if (!x && g)
        flag = 1;
}

void solve()
{
    init();
    cin >> n >> m >> q;
    rep(i, 1, m)
    {
        int x;
        cin >> x;
        insert(x, 1);
    }
    while (q--)
    {
        int x, g = 1, s = 0;
        cin >> x;
        if (flag || !n)
        {
            cout << 0 << "\n";
            continue;
        }
        reb(i, 62, 0) if (x & (1ll << i))
        {
            if (!a[i].w)
            {
                s = 1;
                break;
            }
            else
                x ^= a[i].w, g ^= a[i].v;
        }
        if (!x && g)
        {
            cout << 0 << "\n";
            continue;
        }
        if (n - cnt - s >= 0)
            cout << p[n - cnt - s] << "\n";
        else
            cout << 0 << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    rep(i, 1, 63) p[i] = p[i - 1] * 2ll % MOD;
    cin >> T;
    while (T--)
        solve();
    return 0;
}