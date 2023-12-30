#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e4 + 5;

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

int n, m;
int jd[N];
struct node
{
    int to, nxt, v;
};
node a[N << 1];
int hd[N], cnt;
void add(int x, int y, int z)
{
    cnt++;
    a[cnt].to = y;
    a[cnt].v = z;
    a[cnt].nxt = hd[x];
    hd[x] = cnt;
}

int main()
{
    fre(ans);
    read(n);
    int a, b, c;
    for (int i = 1; i < n; i++)
    {
        read(a), read(b), read(c);
        add(a, b, c);
        add(b, a, c);
    }
    read(m);
    for (int i = 1; i <= m; i++)
        read(jd[i]);
    return 0;
}