#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n, m;
string str[N];
int vis[N][N];
struct node
{
    int x, y;
    int st;
    int lst;
} q[N * N];
int turn[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
char stp[N * N];
int tot;
char goes(node x, node y)
{
    if (x.x - 1 == y.x)
        return 'U';
    if (x.x + 1 == y.x)
        return 'D';
    if (x.y - 1 == y.y)
        return 'L';
    // if (x.y + 1 == y.y)
    return 'R';
}

void bfs()
{
    vis[0][0] = 1;
    int h = 0, r = 0;
    node nxt;
    nxt.x = 0, nxt.y = 0;
    nxt.st = 0, nxt.lst = 0;
    q[r++] = nxt;
    while (h < r)
    {
        if (q[h].x == n - 1 && q[h].y == m - 1)
            break;
        nxt.st = q[h].st + 1;
        nxt.lst = h;
        for (int i = 0; i < 4; i++)
        {
            nxt.x = q[h].x + turn[i][0], nxt.y = q[h].y + turn[i][1];
            if (nxt.x >= 0 && nxt.y >= 0 && nxt.x < n && nxt.y < m && str[nxt.x][nxt.y] != str[q[h].x][q[h].y] && vis[nxt.x][nxt.y] == 0)
            {
                q[r++] = nxt;
                vis[nxt.x][nxt.y] = 1;
            }
        }
        h++;
    }
    if (h < r)
    {
        cout << q[h].st << "\n";
        tot = 1;
        for (int i = h; i; i = q[i].lst, tot++)
            stp[tot] = goes(q[q[i].lst], q[i]);
        while (--tot)
            cout << stp[tot];
        cout << "\n";
    }
    else
        cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> str[i];
        bfs();
        for (int i = 0; i < n; i++)
        {
            str[i] = "";
            for (int j = 0; j < m; j++)
                vis[i][j] = 0;
        }
    }
    return 0;
}