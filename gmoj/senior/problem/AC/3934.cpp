#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;

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
struct edge
{
    int from, nxt;
};
edge a[M];
int hd[N], cnt;
int st, en;
void add(int x, int y)
{
    cnt++;
    a[cnt].from = x;
    a[cnt].nxt = hd[y];
    hd[y] = cnt;
}
struct _edge
{
    int to, nxt;
};
_edge _a[M];
int _hd[N], _cnt;
void _add(int x, int y)
{
    _cnt++;
    _a[cnt].to = y;
    _a[cnt].nxt = _hd[x];
    _hd[x] = _cnt;
}

int step[N];
int q[M];
void find()
{
    int h = 0, r = 0;
    q[r++] = en;
    step[en] = 0;
    while (h < r)
    {
        for (int i = hd[q[h]]; i; i = a[i].nxt)
            if (step[a[i].from] == INF)
                q[r++] = a[i].from, step[a[i].from] = step[q[h]] + 1;
        h++;
    }
}

int ans[N];
bool _check(int k)
{
    for (int i = _hd[k]; i; i = _a[i].nxt)
        if (step[_a[i].to] == INF)
            return 0;
    return 1;
}
void bfs()
{
    int h = 0, r = 0;
    q[r++] = en;
    ans[en] = 0;
    while (h < r)
    {
        for (int i = hd[q[h]]; i; i = a[i].nxt)
            if (ans[a[i].from] == -1 && _check(a[i].from))
                q[r++] = a[i].from, ans[a[i].from] = ans[q[h]] + 1;
        h++;
    }
}

int main()
{
    fre(ans);
    read(n), read(m);
    for (int i = 1; i <= m; i++)
    {
        read(st), read(en);
        add(st, en);
        _add(st, en);
    }
    read(st), read(en);
    memset(step, 0x3f, sizeof(step));
    memset(ans, -1, sizeof(ans));
    find();
    bfs();
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", step[i]);
    // printf("\n");
    // for (int i = 1; i <= n; i++)
    //     printf("%d ", ans[i]);
    printf("%d", ans[st]);
    return 0;
}