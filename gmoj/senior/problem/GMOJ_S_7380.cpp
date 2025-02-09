#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, m, u, v, last[50001], cnt, dis1[50001], dis2[50001];
double w, p1[50001], p2[50001];
struct edge
{
    ll next, to;
    double k;
} e[200001];
struct node
{
    ll x, dis;
    double p;
} d[5000001];
void add(ll u, ll v, double w)
{
    e[++cnt] = {last[u], v, w};
    last[u] = cnt;
}

void bfs(ll x)
{
    rep(i, 1, n) dis1[i] = 1e18, dis2[i] = 1e18;
    d[1] = {x, 0, 1}, dis1[x] = 0, dis2[x] = 0, p1[x] = 1, p2[x] = 1;
    ll hd = 0, tl = 1;
    while (hd < tl)
    {
        ++hd;
        for (int i = last[d[hd].x]; i; i = e[i].next)
        {
            if (d[hd].p * e[i].k >= 0.75)
            {
                if (d[hd].dis + 1 < dis1[e[i].to])
                    dis1[e[i].to] = d[hd].dis + 1, p1[e[i].to] = d[hd].p * e[i].k, d[++tl] = {e[i].to, dis1[e[i].to], p1[e[i].to]};
                if (d[hd].p * e[i].k > p2[e[i].to])
                    dis2[e[i].to] = d[hd].dis + 1, p2[e[i].to] = d[hd].p * e[i].k, d[++tl] = {e[i].to, dis2[e[i].to], p2[e[i].to]};
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> u >> v >> w;
        w /= 100.0;
        add(u, v, w);
        add(v, u, w);
    }
    bfs(1);
    rep(i, 1, n) cout << (dis1[i] < 1e18 ? dis1[i] : -1) << ' ';
    return 0;
}