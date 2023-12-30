#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

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

int m, n;
int a[55][55];
int f[55][55][55][55];

int main()
{
    fre(ans);
    read(m), read(n);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            read(a[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            for (int x = 1; x <= m; x++)
                for (int y = 1; y <= n; y++)
                    if (i + j == x + y && (i != 1 || j != 1) && (i != x || (i == m && j == n)))
                        f[i][j][x][y] = max(max(f[i - 1][j][x - 1][y], f[i - 1][j][x][y - 1]), max(f[i][j - 1][x - 1][y], f[i][j - 1][x][y - 1])) + a[i][j] + a[x][y];
    // for (int i = 1; i <= m; i++)
    //     for (int j = 1; j <= n; j++)
    //         for (int x = 1; x <= m; x++)
    //         {
    //             for (int y = 1; y <= n; y++)
    //                 cout << f[i][j][x][y] << ' ';
    //             cout << endl;
    //         }
    printf("%d", f[m][n][m][n]);
    return 0;
}