#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 2e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, s;
int fa[N][22], mx[N][22], mn[N][22];
int deep[N];
vector<int> e[N];
int ans;

int check(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    int nx = x, ny = y;
    reb(i, s, 0) if (deep[fa[nx][i]] >= deep[ny]) nx = fa[nx][i];
    reb(i, s, 0) if (fa[nx][i] != fa[ny][i]) nx = fa[nx][i], ny = fa[ny][i];
    int lca = nx;
    (nx != ny) && (lca = fa[lca][0]);
    int _max = max(x, y), _min = min(x, y);
    nx = x, ny = y;
    _max = max(_max, lca), _min = min(_min, lca);
    reb(i, s, 0) if (deep[fa[nx][i]] >= deep[lca]) _max = max(_max, mx[nx][i]), _min = min(_min, mn[nx][i]), nx = fa[nx][i];
    reb(i, s, 0) if (deep[fa[ny][i]] >= deep[lca]) _max = max(_max, mx[ny][i]), _min = min(_min, mn[ny][i]), ny = fa[ny][i];
    // cout << x << ' ' << y << ' ' << _max << ' ' << _min << ' ' << (_max == max(x, y) && _min == min(x, y)) << '\n';
    return (_max == max(x, y) && _min == min(x, y));
}
void dfs(int u, int f)
{
    deep[u] = deep[f] + 1;
    for (auto v : e[u])
        dfs(v, u);
}
int son[N];

signed main()
{
    cin >> n;
    rep(i, 1, n) cin >> fa[i][0];
    rep(i, 1, n) e[fa[i][0]].push_back(i), son[fa[i][0]]++;

    int flag = 0;
    rep(i, 1, n) if (e[i].size() == n - 1) flag = i;
    if (flag != 0)
    {
        ll sum = (n - 1) + ((ll)(flag - 1) * (n - flag));
        cout << sum << '\n';
        return 0;
    }
    rep(i, 1, n) if (son[i] != 1) flag++;
    if (flag == 1) // 树退化为链
    {
        ll sum = 0, x, t;
        flag = 0;
        rep(i, 1, n) if (son[i] != 1) x = i;
        t = 1;
        rep(i, 2, n)
        {
            if (x > fa[x][0])
            {
                if (flag != -1)
                    sum += t * (t - 1) / 2, t = 1;
                flag = -1, t++;
            }
            else
            {
                if (flag != 1)
                    sum += t * (t - 1) / 2, t = 1;
                flag = 1, t++;
            }
            x = fa[x][0];
        }
        sum += t * (t - 1) / 2;
        cout << sum << '\n';
        return 0;
    }

    rep(i, 1, n) if (fa[i][0] == 0) fa[i][0] = i;
    dfs(1, 0);
    // rep(i, 1, n) cout << deep[i] << ' ';
    // cout << '\n';
    rep(i, 1, n) mx[i][0] = i, mn[i][0] = i;
    s = __lg(n);
    rep(j, 1, s) rep(i, 1, n) fa[i][j] = fa[fa[i][j - 1]][j - 1], mx[i][j] = max(mx[i][j - 1], mx[fa[i][j - 1]][j - 1]), mn[i][j] = min(mn[i][j - 1], mn[fa[i][j - 1]][j - 1]);
    // rep(j, 0, s) rep(i, 1, n) cout << i << ' ' << j << ' ' << fa[i][j] << ' ' << mx[i][j] << ' ' << mn[i][j] << '\n';
    rep(i, 1, n) rep(j, i + 1, n) ans += check(i, j);
    cout << ans << '\n';
    return 0;
}