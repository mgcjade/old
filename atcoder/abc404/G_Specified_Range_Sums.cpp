#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

struct node
{
    int u, v;
    int w;
    node(int x, int y, int z) : u(x), v(y), w(z) {}
};

int n, m;
vector<node> e;

int a[N];

signed main()
{
    cin >> n >> m;

    rep(i, 1, m)
    {
        int l, r, s;
        cin >> l >> r >> s;
        e.emplace_back(l - 1, r, s), e.emplace_back(r, l - 1, -s);
    }
    rep(i, 1, n) e.emplace_back(i - 1, i, 1);

    memset(a, -0x3f, sizeof(a));
    a[0] = 0;
    rep(i, 1, n)
    {
        int flag = 0;
        for (auto [u, v, w] : e)
            if (a[u] != -INF && a[v] < a[u] + w)
                a[v] = a[u] + w, flag = 1;
        if (!flag)
            break;
    }

    int flag = 0;
    for (auto [u, v, w] : e)
        if (a[u] != -INF && a[v] < a[u] + w)
            flag = 1;
    if (flag || a[n] == -INF)
        cout << -1 << '\n';
    else
        cout << a[n] << '\n';

    return 0;
}