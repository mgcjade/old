#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
struct node
{
    int a, b, c;
    int num;
    int sa;
};
node g[N], s[N], b[N];
int ans[N];
int x, y, z;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> z;
        g[i].a = x, g[i].b = y, g[i].c = z, g[i].num = i;
        s[i].a = x, s[i].b = y, s[i].c = z, s[i].num = i;
        b[i].a = x, b[i].b = y, b[i].c = z, b[i].num = i;
    }
    sort(s + 1, s + n + 1, [](const node &a, const node &b)
         { return a.a > b.a; });
    sort(b + 1, b + n + 1, [](const node &a, const node &b)
         { return a.b > b.b; });
    sort(g + 1, g + n + 1, [](const node &a, const node &b)
         { return a.c > b.c; });
    for (int i = 1; i <= n; i++)
    {
        g[i].sa = i, s[i].sa = i, b[i].sa = i;
        if (g[i].a == g[i - 1].a)
            g[i].sa = g[i - 1].sa;
        if (s[i].b == s[i - 1].b)
            s[i].sa = s[i - 1].sa;
        if (b[i].c == b[i - 1].c)
            b[i].sa = b[i - 1].sa;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ans[g[i].num])
            ans[g[i].num] = g[i].sa;
        if (!ans[s[i].num])
            ans[s[i].num] = s[i].sa;
        if (!ans[b[i].num])
            ans[b[i].num] = b[i].sa;
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << '\n';
    return 0;
}