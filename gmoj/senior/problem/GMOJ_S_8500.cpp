#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
string s;
vector<int> e[N];
int ans[N];
struct edge
{
    int u, v;
} ed[N];
struct node
{
    int fa;
    int sum; // 子树中有多少个节点
    int cnt; // 包含根节点，有多少个节点还没有被加入到树中
} pre[N];
int fnd(int t)
{
    if (pre[t].fa == t)
        return t;
    pre[pre[t].fa].sum += pre[t].sum + 1, pre[t].sum = -1;
    pre[pre[t].fa].cnt += pre[t].cnt, pre[t].cnt = 0;
    return pre[t].fa = fnd(pre[t].fa);
}
void dlt(int t)
{
    pre[t].cnt = max(0ll, pre[t].cnt - 1);
    if (pre[t].fa == t)
        return;
    dlt(pre[t].fa);
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    cin >> s;
    s = ' ' + s;
    rep(i, 1, m)
    {
        cin >> ed[i].u >> ed[i].v;
        if (ed[i].u < ed[i].v || s[ed[i].v] == '1')
            e[ed[i].u].push_back(ed[i].v);
        if (ed[i].v < ed[i].u || s[ed[i].u] == '1')
            e[ed[i].v].push_back(ed[i].u);
    }
    rep(i, 1, n) pre[i].fa = i, pre[i].sum = 0, pre[i].cnt = 1;
    rep(i, 1, n)
    {
        if (s[i] == '0')
            continue;
        for (auto &j : e[i])
        {
            if (s[j] == '0')
                continue;
            int u = fnd(i), v = fnd(j);
            if (u != v)
            {
                pre[v].fa = u;
                pre[u].sum += pre[v].sum + 1, pre[v].sum = -1;
                pre[u].cnt += pre[v].cnt, pre[v].cnt = 0;
            }
        }
    }
    reb(i, n, 1)
    {
        ans[i] = ans[i + 1];
        int u = fnd(i), v;
        if (s[i] == '0')
            dlt(i);
        // cerr << u << ' ';
        for (auto &j : e[i])
        {
            v = fnd(j);
            if (u != v)
            {
                pre[v].fa = u;
                // ans[i] -= pre[u].sum * (pre[u].sum + 1) / 2;
                // ans[i] -= pre[v].sum * (pre[v].sum + 1) / 2;
                ans[i] += (pre[u].sum + 1 - pre[u].cnt) * (pre[v].sum + 1 - pre[v].cnt);
                pre[u].sum += pre[v].sum + 1, pre[v].sum = -1;
                pre[u].cnt += pre[v].cnt, pre[v].cnt = 0;
                // cerr << pre[u].sum << ' ';
                // ans[i] += pre[u].sum * (pre[u].sum + 1) / 2;
            }
        }
        if (s[i] == '1')
        {
            dlt(i);
            ans[i] += pre[u].sum - pre[u].cnt;
        }
        // cerr << pre[u].sum << '\n';
        // cout << ans[i] << '\n';
    }
    rep(i, 1, n) cout << ans[i] << '\n';
    return 0;
}