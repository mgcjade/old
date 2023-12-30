#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

int n, m;
__int128 k;
__int128 ans;
struct node
{
    int u, v;
    __int128 w;
};
node a[30];
bool cmp(node x, node y) { return x.w < y.w; }
int pre[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int find(int t) { return pre[t] == t ? t : pre[t] = find(pre[t]); }

inline void read(__int128 &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}
void otp(__int128 s)
{
    if (s > 9)
        otp(s / 10);
    printf("%d", (int)(s % 10));
}

int main()
{
    scanf("%d%d", &n, &m);
    read(k);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a[i].u, &a[i].v), read(a[i].w);
    sort(a + 1, a + m + 1, cmp);
    // printf("\n");

    // printf("\n");
    int i = 1;
    while (n > 1)
    {
        int u = find(a[i].u), v = find(a[i].v);
        if (u != v)
        {
            pre[v] = u;
            n--;
            ans = (ans + a[i].w) % k;
            // printf("%d %d\n", u, v);
        }
        i++;
        // printf("%d %lld\n", n, ans);
    }
    otp(ans);
    return 0;
}