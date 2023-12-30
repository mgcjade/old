#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int MOD = 1e4 + 7;

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

int n;
struct edge
{
    int to, nxt;
};
edge a[N];
int hd[N], cnt;
void add(int x, int y)
{
    cnt++;
    a[cnt].to = y;
    a[cnt].nxt = hd[x];
    hd[x] = cnt;
}
int x, y;
int w[N];
ll s[N], S[N];
int _mx[N], _cmx[N];
int ans, mx;

int main()
{
    fre(ans);
    read(n);
    for (int i = 1; i < n; i++)
    {
        read(x), read(y);
        add(x, y), add(y, x);
    }
    for (int i = 1; i <= n; i++)
        read(w[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = hd[i]; j; j = a[j].nxt)
        {
            s[i] += w[a[j].to];
            S[i] += w[a[j].to] * w[a[j].to];
            if (w[a[j].to] > _mx[i])
                _cmx[i] = _mx[i], _mx[i] = w[a[j].to];
            else if (w[a[j].to] > _cmx[i])
                _cmx[i] = w[a[j].to];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = (ans + (s[i] * s[i] - S[i]) % MOD) % MOD;
        mx = max(mx, _mx[i] * _cmx[i]);
    }
    printf("%d %d", mx, ans);
    return 0;
}