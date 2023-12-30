#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline void read(int &s)
{
    scanf("%d", &s);
}

int n, m;
int sum[N][N];
char ch[N];
int a, b, c, d;
ll ans;

int main()
{
    read(n), read(m);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", ch);
        for (int j = 0; j < n; j++)
        {
            sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + (ch[j] == 'B');
        }
    }

    while (m--)
    {
        read(a), read(b), read(c), read(d);
        int x, y;

        x = min((a / n + 1) * n, c + 1);
        y = min((b / n + 1) * n, d + 1);
        ans = sum[x][y] - sum[a][b + 1] - sum[a + 1][b] + sum[a][b];
        printf("%d %d\n", x, y);

        if (x == c + 1 && d / n >= b / n)
        {
            y = d / n * n;
            if (d / n > b / n)
                ans += (sum[x][n] - sum[a][n]) * (d / n - b / n - 1);
            ans += (sum[x][d % n + 1] - sum[a][d % n + 1]);
        }

        printf("%lld\n", ans);
    }
    return 0;
}