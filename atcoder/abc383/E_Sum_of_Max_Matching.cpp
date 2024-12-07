#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, m, k;
int ans;

struct Node
{
    int x, y, z;
} a[N];

int fa[N];
int AA[N], BB[N];

int fnd(int x) { return fa[x] = x == fa[x] ? x : fnd(fa[x]); }
bool cmp(Node a, Node b) { return a.z < b.z; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i].x >> a[i].y >> a[i].z;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        AA[x]++;
    }
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        BB[x]++;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = fnd(a[i].x), v = fnd(a[i].y);
        if (u != v)
        {
            fa[v] = u;
            AA[u] += AA[v];
            BB[u] += BB[v];
            int o = min(AA[u], BB[u]);
            AA[u] -= o, BB[u] -= o;
            ans += o * a[i].z;
        }
    }
    cout << ans << '\n';
    return 0;
}