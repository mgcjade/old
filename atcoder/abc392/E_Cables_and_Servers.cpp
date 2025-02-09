#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
struct edge
{
    int u, v;
    int num;
} e[N];
bool cmp(edge a, edge b) { return a.u < b.u; }
int tot;

int k;
int pre[N];
int fnd(int t) { return pre[t] = (pre[t] == t ? t : fnd(pre[t])); }
queue<edge> q;
vector<int> p;

array<int, 3> ans[N];
int cnt;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) pre[i] = i;
    rep(i, 1, m)
    {
        int u, v;
        cin >> u >> v;
        if (fnd(u) != fnd(v))
            pre[fnd(u)] = fnd(v);
        else
            e[++tot] = {u, v, i};
    }
    sort(e + 1, e + tot + 1, cmp);
    int x = 1;
    rep(i, 1, tot)
    {
        while (fnd(e[i].u) == fnd(x) && x <= n)
            ++x;
        if (x > n)
            break;
        cnt++;
        ans[i] = {e[i].num, e[i].u, x};
        pre[fnd(e[i].u)] = fnd(x);
    }
    cout << cnt << '\n';
    rep(i, 1, cnt) cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << '\n';
    return 0;
}