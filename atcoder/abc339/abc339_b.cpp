#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 105;

int n, m, k;
int b[N][N];
char ch[3];
int x, y, fx;
int mv[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

int main()
{
    memset(b, -1, sizeof(b));
    ch[0] = '.', ch[2] = '#';
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= k; i++)
    {
        fx = (fx - b[x][y] + 4) % 4;
        b[x][y] = b[x][y] * -1;
        x = (x + mv[fx][0] + n) % n, y = (y + mv[fx][1] + m) % m;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%c", ch[b[i][j] + 1]);
        printf("\n");
    }
    return 0;
}