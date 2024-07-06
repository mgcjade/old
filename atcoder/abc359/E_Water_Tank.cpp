#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
ll a[N];
ll ans[N] = {1};
ll mx;
int w;
int x;
int l[N], r[N], k[N];
struct node
{
    int v, num;
};
node A[N];
bool cmp(node x, node y) { return x.v == y.v ? x.num < y.num : x.v < y.v; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        A[i].v = a[i];
        A[i].num = i;
    }
    sort(A + 1, A + n + 1, cmp);
    for (int i = 1; i <= n; ++i)
        k[i] = A[i].num;
    for (int i = 1; i <= n; ++i)
    {
        r[i] = i + 1;
        l[i] = i - 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        l[r[k[i]]] = l[k[i]];
        r[l[k[i]]] = r[k[i]];
    }
    // for (int i = 1; i <= n; i++)
    //     cout << l[i] << ' ';
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= mx)
            mx = a[i], w = i, x = 0;
        else
            x = l[i];
        if (mx > a[i])
            ans[i] = ans[x] + a[i] * (i - x);
        else
        {
            ans[i] = ans[0] + a[i] * i;
            mx = a[i];
            w = i;
            x = i;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}