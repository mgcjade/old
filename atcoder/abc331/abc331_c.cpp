#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

ll n;
struct node
{
    ll v, num, sum, ans;
} a[200005];
bool cmp(node x, node y) { return x.v < y.v; }
bool cmpp(node x, node y) { return x.num < y.num; }

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i].v);
        a[i].num = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = n; i; i--)
        a[i].sum = a[i + 1].sum + a[i].v;
    for (int i = n - 1; i; i--)
        a[i].ans = a[i].v < a[i + 1].v ? a[i + 1].sum : a[i + 1].ans;
    sort(a + 1, a + n + 1, cmpp);
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i].ans);
    return 0;
}