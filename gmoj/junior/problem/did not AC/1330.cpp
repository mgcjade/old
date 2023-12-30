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

int n;
int ans[7][3];

void dfs(int step, int a[5][7])
{
    bool flag = 1;
    while (flag)
    {
        int t;
        flag = 0;
        for (int i = 0; i < 5; i++)
        {
            t = 0;
            for (int j = 0; j < 7; j++)
            {
                if (a[i][j] != 0)
                {
                    swap(a[i][j], a[i][t]);
                    t++;
                }
            }
        }
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                if (a[i][j] == a[i][j + 1] && a[i][j + 1] == a[i][j + 2] && a[i][j] != 0)
                    a[i][j] = a[i][j + 1] = a[i][j + 2] = 0, flag = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 7; j++)
                if (a[i][j] == a[i + 1][j] && a[i + 1][j] == a[i + 2][j] && a[i][j] != 0)
                    a[i][j] = a[i + 1][j] = a[i + 2][j] = 0, flag = 1;
    }
    if (step == n + 1)
    {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 7; j++)
                if (a[i][j] != 0)
                    return;
        for (int i = 1; i <= n; i++)
            printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
        return;
        exit(0);
    }
    for (int i = 0; i < 5; i++)
    {
        int j = 0;
        while (a[i][j] > 0 && j < 7)
        {
            if (i < 4)
            {
                swap(a[i + 1][j], a[i][j]);
                ans[step][0] = i;
                ans[step][1] = j;
                ans[step][2] = 1;
                dfs(step + 1, a);
                swap(a[i + 1][j], a[i][j]);
            }
            if (i > 0)
            {
                swap(a[i - 1][j], a[i][j]);
                ans[step][0] = i;
                ans[step][1] = j;
                ans[step][2] = -1;
                dfs(step + 1, a);
                swap(a[i - 1][j], a[i][j]);
            }
            j++;
        }
    }
}

int a[5][7];
int main()
{
    fre(ans);
    read(n);
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            read(a[i][j]);
            if (a[i][j] == 0)
                break;
        }
    }
    dfs(1, a);
    printf("-1");
    return 0;
}