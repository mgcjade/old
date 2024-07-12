#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 20;
const int M = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

bool bri[N][N];
int T;
int n, m;
struct edge
{
    int to, nxt;
} e[M];
int hd[N], cnt;
void add_edge(int x, int y)
{
    ++cnt;
    e[cnt].to = y;
    e[cnt].nxt = hd[x];
    hd[x] = cnt;
}

ll f[N][N][10000], g[N][N][10000], a[N];
ll sum;

void init(int k)
{
    sum = 0;
    cnt = 0;
    memset(hd, 0, sizeof(hd));
    memset(bri, 0, sizeof(bri));
    memset(f, -0x3f, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 1; i <= n; i++)
    {
        f[i][0][1 << (i - 1)] = 0;
        g[i][0][1 << (i - 1)] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int s;
    ll mx, ans;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        init(n);
        for (int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 1; i <= m; ++i)
        {
            int x, y;
            cin >> x >> y;
            if (!bri[x][y])
            {
                add_edge(x, y);
                add_edge(y, x);
            }
            bri[x][y] = bri[y][x] = true;
        }
        s = (1 << n) - 1;
        for (int l = 1; l <= s; l++)
            for (int i = 1; i <= n; i++)
                if (l & (1 << (i - 1)))
                    for (int j = 0; j <= n; j++)
                        if (g[i][j][l])
                            for (int k = hd[i]; k; k = e[k].nxt)
                                if (!(l & (1 << (e[k].to - 1))))
                                {
                                    if (f[i][j][l] + a[i] * a[e[k].to] + (ll)bri[j][e[k].to] * a[i] * a[j] * a[e[k].to] > f[e[k].to][i][l | 1 << (e[k].to - 1)])
                                    {
                                        f[e[k].to][i][l | 1 << (e[k].to - 1)] = f[i][j][l] + a[i] * a[e[k].to] + (ll)bri[j][e[k].to] * a[i] * a[j] * a[e[k].to];
                                        g[e[k].to][i][l | 1 << (e[k].to - 1)] = g[i][j][l];
                                    }
                                    else if (f[i][j][l] + a[i] * a[e[k].to] + (ll)bri[j][e[k].to] * a[i] * a[j] * a[e[k].to] == f[e[k].to][i][l | 1 << (e[k].to - 1)])
                                        g[e[k].to][i][l | 1 << (e[k].to - 1)] += g[i][j][l];
                                }
        mx = 0, ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j <= n; j++)
                if (f[i][j][(1 << n) - 1] > mx)
                {
                    mx = f[i][j][(1 << n) - 1];
                    ans = g[i][j][(1 << n) - 1];
                }
                else if (f[i][j][(1 << n) - 1] == mx)
                    ans += g[i][j][(1 << n) - 1];
        if (mx + sum == 0 || ans == 0)
            cout << "0 0" << '\n';
        else
            cout << mx + sum << ' ' << ((ans + 1) >> 1) << '\n';
    }
    return 0;
}