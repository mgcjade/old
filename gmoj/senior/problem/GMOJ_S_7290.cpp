#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

const int MAXN = 1e5 + 5;
const int LOG = 20;

vector<int> tree[MAXN];
int n, m;
int parent[MAXN], depth[MAXN], siz[MAXN], in_time[MAXN], out_time[MAXN], son[MAXN], cson[MAXN];
int up[LOG][MAXN], val[MAXN];

void dfs(int u, int p)
{
    parent[u] = p;
    in_time[u] = ++in_time[0];
    siz[u] = 1;
    int max1 = -1, max2 = -1;
    int s1 = -1, s2 = -1;
    for (int v : tree[u])
    {
        if (v == p)
            continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > max1)
        {
            max2 = max1;
            s2 = s1;
            max1 = siz[v];
            s1 = v;
        }
        else if (siz[v] > max2)
        {
            max2 = siz[v];
            s2 = v;
        }
    }
    son[u] = s1;
    cson[u] = s2;
    out_time[u] = ++out_time[0];
    val[u] = (s1 != -1 ? siz[s1] : 0) - (s2 != -1 ? siz[s2] : 0);
}

bool is_ancestor(int a, int b)
{
    return in_time[a] <= in_time[b] && out_time[b] <= out_time[a];
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (depth[u] - (1 << i) >= depth[v])
        {
            u = up[i][u];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG - 1; i >= 0; --i)
    {
        if (up[i][u] != up[i][v])
        {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return parent[u];
}

int find_center(int root, int x, int y)
{
    int total = n - siz[x] - siz[y];
    int u = root;
    for (int i = LOG - 1; i >= 0; --i)
    {
        int next = up[i][u];
        if (next == -1)
            continue;
        if (is_ancestor(x, next) || is_ancestor(y, next))
            continue;
        if (val[next] - siz[x] - siz[y] > 0)
        {
            u = next;
        }
    }
    return u;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    dfs(1, -1);

    for (int u = 1; u <= n; ++u)
    {
        up[0][u] = son[u];
    }

    for (int k = 1; k < LOG; ++k)
    {
        for (int u = 1; u <= n; ++u)
        {
            if (up[k - 1][u] == -1)
            {
                up[k][u] = -1;
            }
            else
            {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;

        if (x == y)
        {
            cout << 0 << endl;
            continue;
        }

        int del_size = siz[x] + siz[y];
        if (del_size >= n)
        {
            cout << 0 << endl;
            continue;
        }

        int total = n - del_size;
        if (total == 0)
        {
            cout << 0 << endl;
            continue;
        }

        int root = 1;
        if (is_ancestor(x, root) || is_ancestor(y, root))
        {
            root = lca(x, y);
        }

        int new_center = find_center(root, x, y);
        cout << new_center << endl;
    }

    return 0;
}