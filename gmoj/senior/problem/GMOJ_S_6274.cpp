#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
struct node
{
    int l, r;
};
node a[N];
bool cmp(node x, node y) { return x.l == y.l ? x.r < y.r : x.l < y.l; }
int p[N];
int ans;

node q[N];
bool check(node x, node y) { return x.r < y.r; }
int tot;
void pushup(int k)
{
    while (k && check(q[k], q[k >> 1]))
    {
        swap(q[k], q[k >> 1]);
        k >>= 1;
    }
}
void popdown(int k)
{
    while ((k << 1) <= tot)
    {
        if ((k << 1) + 1 <= tot && !check(q[k], q[(k << 1) + 1]) && check(q[(k << 1) + 1], q[k << 1]))
        {
            swap(q[k], q[(k << 1) + 1]);
            k = (k << 1) + 1;
        }
        else if (!check(q[k], q[k << 1]))
        {
            swap(q[k], q[k << 1]);
            k = k << 1;
        }
        else
            return;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    sort(p + 1, p + m + 1);
    int h = 1;
    for (int i = 1; i <= m; i++)
    {
        while (h <= n && a[h].l <= p[i])
        {
            tot++;
            q[tot] = a[h];
            h++;
            pushup(tot);
        }
        while (tot > 0 && q[1].r < p[i])
        {
            swap(q[1], q[tot]);
            tot--;
            popdown(1);
        }
        if (tot > 0)
        {
            swap(q[1], q[tot]);
            tot--;
            popdown(1);
            ans++;
            // cout << q[tot + 1].l << " " << q[tot + 1].r << ' ' << p[i] << '\n';
        }
    }
    cout << ans << '\n';
    return 0;
}