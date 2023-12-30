#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int ans = -1;
int a[9][9];
bool used[3][9][9];
int v[9][9] = {
    {6, 6, 6, 6, 6, 6, 6, 6, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 9, 10, 9, 8, 7, 6},
    {6, 7, 8, 9, 9, 9, 8, 7, 6},
    {6, 7, 8, 8, 8, 8, 8, 7, 6},
    {6, 7, 7, 7, 7, 7, 7, 7, 6},
    {6, 6, 6, 6, 6, 6, 6, 6, 6}};
inline int cnt()
{
    int ret = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            ret = ret + a[i][j] * v[i][j];
    return ret;
}
inline int gg(int x, int y) { return x / 3 * 3 + y / 3; }

inline void dfs(int x, int y)
{
    if (x < 0)
    {
        ans = max(ans, cnt());
        return;
    }
    if (a[x][y])
    {
        dfs(x - (y + 1) / 9, (y + 1) % 9);
        return;
    }
    int t = gg(x, y);
    for (int i = 1; i <= 9; i++)
    {
        if (!used[0][x][i] && !used[1][y][i] && !used[2][t][i])
        {
            a[x][y] = i;
            used[0][x][i] = used[1][y][i] = used[2][t][i] = 1;
            dfs(x - (y + 1) / 9, (y + 1) % 9);
            used[0][x][i] = used[1][y][i] = used[2][t][i] = 0;
        }
    }
    a[x][y] = 0;
}

int main()
{
    // fre(ans);
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j])
                used[0][i][a[i][j]] = used[1][j][a[i][j]] = used[2][gg(i, j)][a[i][j]] = 1;
        }
    dfs(8, 0);
    printf("%d", ans);
    return 0;
}