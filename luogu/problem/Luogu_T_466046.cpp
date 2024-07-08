#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
ll ans;
int nw[N];

int hd[N], to[N], nxt[N], tot;
void add(int u, int v)
{
    to[++tot] = v;
    nxt[tot] = hd[u];
    hd[u] = tot;
}

void dfs(int k, int fa)
{
    ll s = nw[a[k]], sum = 0, opt = nw[a[k]];
    for (int i = hd[k]; i; i = nxt[i])
    {
        if (to[i] != fa)
        {
            dfs(to[i], k);
            sum += (ll)(s - opt) * (nw[a[k]] - s);
            s = nw[a[k]];
        }
    }
    for (int i = 1; i * i <= a[k]; i++)
    {
        if (a[k] % i == 0)
        {
            nw[i]++;
            if (i * i != a[k])
                nw[a[k] / i]++;
        }
    }
    ans += (sum << 1) + ((s - opt) << 1) + 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    dfs(1, -1);
    cout << ans << '\n';
    return 0;
}