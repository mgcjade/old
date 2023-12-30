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

int n;
int a[1005];
int v[1005][1005];

struct node
{
    int a, b;
};
int fst(int h)
{
    int mn = 0x3f3f3f3f, ret;
    for (int i = h + 1; i <= n; i++)
    {
        if (v[h][i] < mn || (v[h][i] == mn && a[ret] > a[i]))
            mn = v[h][i], ret = i;
    }
    return ret;
}
int sec(int h)
{
    int mn = 0x3f3f3f3f, ret, w, lst = 0x3f3f3f3f;
    for (int i = h + 1; i <= n; i++)
    {
        if (v[h][i] < mn || (v[h][i] == mn && a[w] > a[i]))
            lst = mn, ret = w, mn = v[h][i], w = i;
        else if (v[h][i] < lst || (v[h][i] == lst && a[ret] > a[i]))
            lst = v[h][i], ret = i;
    }
    return ret;
}
node go(int st, int s)
{
    node ret;
    ret.a = ret.b = 0;
    bool flag = 1;
    int nw = st;
    int p;
    while (1)
    {
        if (nw >= n)
        {
            return ret;
        }
        if (flag)
        {
            p = sec(nw);
            ret.a += v[nw][p];
            flag = !flag;
            if (ret.a + ret.b > s)
            {
                ret.a -= v[nw][p];
                return ret;
            }
        }
        else
        {
            p = fst(nw);
            ret.b += v[nw][p];
            flag = !flag;
            if (ret.a + ret.b > s)
            {
                ret.b -= v[nw][p];
                return ret;
            }
        }
        nw = p;
    }
}

int s, m;

int main()
{
    fre(ans);
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        for (int j = 1; j < i; j++)
            v[j][i] = abs(a[i] - a[j]);
    }
    read(s);
    int ans;
    double mn = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        node t = go(i, s);
        double p;
        if (t.b == 0)
        {
            if (t.a == 0)
                p = 1;
            else
                p = 0x3f3f3f3f;
        }
        else
            p = t.a / 1.0 / t.b;

        if (p < mn)
            mn = p, ans = i;
    }
    printf("%d\n", ans);
    read(m);
    int a, b;
    while (m--)
    {
        read(a), read(b);
        node t = go(a, b);
        printf("%d %d\n", t.a, t.b);
    }
    return 0;
}