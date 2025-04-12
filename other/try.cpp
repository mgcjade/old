#include <cmath>
#include <cstdio>
using namespace std;
const int MAXN = 3000;
int T, n;
struct Star
{
    int x, y, c;
} a[MAXN + 10];
int c0, c1, c2, t[MAXN + 10][3];
long double mymax(long double x, long double y)
{
    return x > y ? x : y;
}
long double dis(int x, int y, int xx, int yy)
{
    return sqrtl(1ll * (x - xx) * (x - xx) + 1ll * (y - yy) * (y - yy));
}
int main(void)
{
    scanf("%d", &T);
    while (T--)
    {
        c0 = c1 = c2 = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].c);
            if (a[i].c == 0)
            {
                t[++c0][0] = i;
            }
            else if (a[i].c == 1)
            {
                t[++c1][1] = i;
            }
            else if (a[i].c == 2)
            {
                t[++c2][2] = i;
            }
        }
        long double ans = 0;
        for (int i = 1; i <= c0; i++)
        {
            for (int j = 1; j <= c1; j++)
            {
                long double d1 = dis(a[t[i][0]].x, a[t[i][0]].y, a[t[j][1]].x, a[t[j][1]].y);
                for (int k = 1; k <= c2; k++)
                {
                    long double d2 = dis(a[t[i][0]].x, a[t[i][0]].y, a[t[k][2]].x, a[t[k][2]].y);
                    long double d3 = dis(a[t[j][1]].x, a[t[j][1]].y, a[t[k][2]].x, a[t[k][2]].y);
                    long double p = (d1 + d2 + d3) / 2.0;
                    ans = mymax(ans, sqrtl(1.0 * p * (p - d1) * (p - d2) * (p - d3)));
                }
            }
        }
        printf("%.1Lf\n", ans);
    }
    return 0;
}