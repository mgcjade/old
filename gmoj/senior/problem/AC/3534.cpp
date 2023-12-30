#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

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

int n, m, q;
int pre[20005];
int son[20005][2];
int fa[20005][16];
int w[20005];
int dth[20005];
struct node
{
    int x, y, z;
};
node a[50005];
bool cmp(node x, node y) { return x.z > y.z; }
void Sort(int h, int r)
{
    int i = h, j = r;
    node mid = a[(h + r) >> 1];
    while (i <= j)
    {
        while (cmp(a[i], mid))
            i++;
        while (cmp(mid, a[j]))
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++, j--;
        }
    }
    if (h < j)
        Sort(h, j);
    if (i < r)
        Sort(i, r);
}
int find(int t) { return pre[t] == t ? t : pre[t] = find(pre[t]); }
void dfs(int t)
{
    dth[t] = dth[fa[t][0]] + 1;
    if (son[t][0])
        dfs(son[t][0]);
    if (son[t][1])
        dfs(son[t][1]);
}

int main()
{
    fre(ans);
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        pre[i] = i, pre[i + n] = i + n;
    for (int i = 1; i <= m; i++)
        read(a[i].x), read(a[i].y), read(a[i].z);
    Sort(1, m);
    int cnt = n;
    for (int i = 1; i <= n << 1; i++)
        fa[i][0] = i;
    for (int i = 1; i <= m; i++)
    {
        int u = find(a[i].x), v = find(a[i].y);
        if (u != v)
        {
            cnt++;
            w[cnt] = a[i].z;
            son[cnt][0] = pre[u], son[cnt][1] = pre[v];
            fa[pre[u]][0] = fa[pre[v]][0] = cnt;
            pre[u] = cnt, pre[v] = cnt;
        }
    }
    int s = log2(cnt);
    for (int i = 1; i <= s; i++)
        for (int j = 1; j <= cnt; j++)
            fa[j][i] = fa[fa[j][i - 1]][i - 1];
    for (int i = 1; i <= cnt; i++)
    {
        if (fa[i][1] == i)
        {
            dfs(i);
        }
    }
    // for (int i = 1; i <= cnt; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //         printf("%d ", fa[i][j]);
    //     printf("\n");
    // }
    int x, y;
    read(q);
    while (q--)
    {
        read(x), read(y);
        if (find(x) != find(y))
        {
            printf("-1\n");
            continue;
        }
        if (dth[x] > dth[y])
            swap(x, y);
        for (int i = s; i >= 0; i--)
            if (dth[fa[y][i]] >= dth[x])
                y = fa[y][i];
        // printf("%d %d ", dth[x], dth[y]);
        for (int i = s; i >= 0; i--)
            if (fa[x][i] != fa[y][i])
                x = fa[x][i],
                y = fa[y][i];
        printf("%d\n", w[fa[x][0]]);
    }
    return 0;
}