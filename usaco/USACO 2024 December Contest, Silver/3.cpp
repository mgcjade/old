#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int x, y;
char to[1005][1005];
int turn[128][2];
int ans;
bool bz[1005][1005];
queue<pair<int, int>> q;
pair<int, int> t;

int main()
{
    turn['L'][0] = 0, turn['L'][1] = -1;
    turn['R'][0] = 0, turn['R'][1] = 1;
    turn['U'][0] = -1, turn['U'][1] = 0;
    turn['D'][0] = 1, turn['D'][1] = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            to[i][j] = '?';
    while (k--)
    {
        cin >> x >> y;
        cin >> to[x][y];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                bz[i][j] = 0;
        ans = n * n;
        while (!q.empty())
            q.pop();
        for (int i = 1; i <= n; i++)
        {
            if ((to[1][i] == 'U' || to[1][i] == '?') && bz[1][i] == 0)
                q.push(make_pair(1, i)), bz[1][i] = 1;
            if ((to[n][i] == 'D' || to[n][i] == '?') && bz[n][i] == 0)
                q.push(make_pair(n, i)), bz[n][i] = 1;
            if ((to[i][1] == 'L' || to[i][1] == '?') && bz[i][1] == 0)
                q.push(make_pair(i, 1)), bz[i][1] = 1;
            if ((to[i][n] == 'R' || to[i][n] == '?') && bz[i][n] == 0)
                q.push(make_pair(i, n)), bz[i][n] = 1;
        }
        while (!q.empty())
        {
            ans--;
            t = q.front();
            q.pop();
            for (auto i : {'L', 'R', 'U', 'D'})
            {
                int nx = t.first + turn[i][0], ny = t.second + turn[i][1];
                if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && bz[nx][ny] == 0 && (to[nx][ny] == '?' || (turn[i][0] + turn[to[nx][ny]][0] == 0 && turn[i][1] + turn[to[nx][ny]][1] == 0)))
                {
                    q.push(make_pair(nx, ny));
                    bz[nx][ny] = 1;
                }
            }
            // cout << t.first << ' ' << t.second << '\n';
        }
        cout << ans << '\n';
    }
    return 0;
}