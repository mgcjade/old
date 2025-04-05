#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "m", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

const int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

int n, m;
int sx, sy, ex, ey;
int st[N][N], mp[N][N];

struct Comp
{
    bool operator()(const array<int, 3> &a, const array<int, 3> &b) const { return a[2] == b[2] ? abs(a[0] - ex) + abs(a[1] - ey) > abs(b[0] - ex) + abs(b[1] - ey) : a[2] > b[2]; }
};

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(st, 0x3f, sizeof(st));
    cin >> n >> m;
    rep(i, 1, n) rep(j, 1, m)
    {
        char ch;
        cin >> ch;
        mp[i][j] = ch == '#';
    }
    cin >> sx >> sy >> ex >> ey;

    st[ex][ey] = abs(sx - ex) + abs(sy - ey);
    priority_queue<array<int, 3>, vector<array<int, 3>>, Comp> q;
    q.push({sx, sy, 0});
    while (!q.empty())
    {
        auto [x, y, d] = q.top();
        q.pop();
        if (st[x][y] <= d || d >= st[ex][ey])
            continue;
        st[x][y] = d;
        ref(i, 0, 4)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || mp[nx][ny] || st[nx][ny] <= d || d >= st[ex][ey])
                continue;
            q.push({nx, ny, d});
        }
        ref(i, 0, 4)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny] <= d + 1 || d + 1 >= st[ex][ey])
                continue;
            q.push({nx, ny, d + 1});
        }
        ref(i, 0, 4)
        {
            int nx = x + dx[i] + dx[i], ny = y + dy[i] + dy[i];
            if (nx < 1 || nx > n || ny < 1 || ny > m || st[nx][ny] <= d + 1 || d + 1 >= st[ex][ey])
                continue;
            q.push({nx, ny, d + 1});
        }
    }
    cout << st[ex][ey] << '\n';
    return 0;
}
