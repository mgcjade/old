#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
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
    if (last == '-')
        s = -s;
}

int n, m;
int a, b, c, s;
int v[15][15];
int wei[15];
int cst[5000][5000];
int f[15][5000];
int ans = INF;

int main()
{
    wei[1] = 1;
    for (int i = 2; i <= 14; i++)
        wei[i] = wei[i - 1] << 1;
    memset(v, 0x3f, sizeof(v));
    memset(cst, 0x3f, sizeof(cst));
    fre(ans);
    read(n), read(m);
    if (n == 1)
    {
        printf("0");
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        read(a), read(b), read(c);
        v[a][b] = v[b][a] = min(v[a][b], c);
    }
    s = pow(2, n) - 1;
    for (int i = 0; i <= s; i++)
        for (int j = 1; j <= n; j++)
            if ((i & wei[j]) == 0)
                for (int k = 1; k <= n; k++)
                    if ((i & wei[k]) == wei[k])
                        cst[i][i | wei[j]] = min(cst[i][i | wei[j]], v[k][j]);
    for (int i = 0; i <= s; i++)
    {
        cst[i][i] = 0;
        for (int j = i + 1; j <= s; j++)
            if ((i & j) == i)
                for (int k = j; k; k = (k - 1) & j)
                    if ((j & k & i) == i)
                        cst[i][j] = min(cst[i][j], cst[i][k] + cst[i][j ^ i ^ k]);
    }
    // for (int i = 0; i <= s; i++)
    // {
    //     for (int j = 0; j <= s; j++)
    //         printf("%d ", cst[i][j]);
    //     printf("\n");
    // }

    for (int k = 1; k <= n; k++)
    {
        memset(f, 0x3f, sizeof(f));
        f[0][wei[k]] = 0;
        for (int st = 1; st <= n; st++)
        {
            for (int i = 0; i <= s; i++)
                for (int j = (i ^ s); j; j = (j - 1) & (i ^ s))
                    if (cst[i][i | j] != INF)
                        f[st][i | j] = min(f[st][i | j], f[st - 1][i] + st * cst[i][i | j]);
            ans = min(ans, f[st][s]);
        }
    }
    printf("%d", ans);
    return 0;
}