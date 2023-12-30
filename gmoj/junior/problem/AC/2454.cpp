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

int n, m;
int cnt;
bool gs[505][505][505];
int a[505][505];
int l[505], r[505];

int vis[505][505];
int turn[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void fnd(int x, int y, int h)
{
    gs[h][x][y] = 1;
    vis[x][y]++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + turn[i][0], ny = y + turn[i][1];
        if (nx > 0 && ny > 0 && nx <= n && ny <= m && a[nx][ny] < a[x][y] && !gs[h][nx][ny])
        {
            fnd(nx, ny, h);
        }
    }
}

int main()
{
    fre(ans);
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            read(a[i][j]);
    for (int i = 1; i <= m; i++)
    {
        fnd(1, i, i);
    }
    int flag = 0;
    for (int i = 1; i <= m; i++)
        if (!vis[n][i])
            flag++;
    if (flag)
    {
        printf("0\n%d", flag);
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
            if (gs[i][n][j])
            {
                if (l[i] == 0)
                    l[i] = j;
                r[i] = j;
            }
    }
    int mx, lst = 1;
    while (lst <= m)
    {
        mx = 0;
        for (int j = 1; j <= m; j++)
            if (l[j] <= lst && r[j] >= lst)
                mx = max(mx, r[j]);
        cnt++;
        lst = mx + 1;
    }
    printf("1\n%d", cnt);
    return 0;
}