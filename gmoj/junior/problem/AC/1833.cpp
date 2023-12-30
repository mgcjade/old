#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define en st + l
using namespace std;
typedef long long ll;

const int N = 305;

int n, m;
int f[N][N];
int ans = 0x7f7f7f7f;

void init()
{
    scanf("%d%d", &n, &m);
    int a, b, c;
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        f[a][b] = f[b][a] = c;
    }
}
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%d ", f[i][j]);
    //     printf("\n");
    // }
}
void find()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (f[i][j] <= m)
            {
                int mx = 0;
                for (int k = 1; k <= n; k++)
                    mx = max(mx, (f[k][i] + f[k][j] - f[i][j]) / 2);
                ans = min(ans, mx);
            }
}

int main()
{
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < N; i++)
        f[i][i] = 0;
    fre(ans);
    init();
    floyd();
    find();
    printf("%d", ans);
    return 0;
}