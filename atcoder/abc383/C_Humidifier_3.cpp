#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, d, k;
int a[N];
int ans;
string str[N];
int vis[N][N];

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> d;
    for (int i = 1; i <= n; i++)
        cin >> str[i], str[i] = ' ' + str[i];

    queue<tuple<int, int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (str[i][j] == 'H')
                q.push({i, j, 0}), ans++, vis[i][j] = 1;

    while (!q.empty())
    {
        auto [x, y, step] = q.front();
        q.pop();
        if (step == d)
            continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m || str[nx][ny] == '#' || vis[nx][ny])
                continue;
            ans++;
            q.push({nx, ny, step + 1}), vis[nx][ny] = 1;
        }
    }
    cout << ans << '\n';
    return 0;
}