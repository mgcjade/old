#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int ans;
int b[N];
string s[N], t;
int f[30][30], vis[N][N][2];
char ch[N][N];

int start_x, start_y, end_x, end_y;
int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

signed main()
{
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> ch[i];
        rep(j, 1, m)
        {
            if (ch[i][j - 1] == 'S')
                start_x = i, start_y = j;
            if (ch[i][j - 1] == 'G')
                end_x = i, end_y = j;
        }
    }

    queue<array<int, 4>> q;
    q.push({start_x, start_y, 0, -1});
    vis[start_x][start_y][0] = vis[start_x][start_y][1] = 1;

    while (!q.empty())
    {
        auto [x, y, len, t] = q.front();
        q.pop();
        if (x == end_x && y == end_y)
            return cout << len, 0;
        if (t != 0)
        {
            rep(i, 0, 1)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny][0] == 1 || ch[nx][ny - 1] == '#')
                    continue;
                vis[nx][ny][0] = 1;
                q.push({nx, ny, len + 1, 0});
            }
        }
        if (t != 1)
        {
            rep(i, 2, 3)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny][1] == 1 || ch[nx][ny - 1] == '#')
                    continue;
                vis[nx][ny][1] = 1;
                q.push({nx, ny, len + 1, 1});
            }
        }
    }
    cout << -1;
    return 0;
}
