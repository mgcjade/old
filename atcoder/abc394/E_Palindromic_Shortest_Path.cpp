#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 105;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
char e[N][N];
vector<int> v[N][26];
int f[N][N];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

signed main()
{
    memset(f, 0x3f, sizeof(f));
    cin >> n;
    rep(i, 1, n) cin >> e[i] + 1;
    rep(i, 1, n) rep(j, 1, n) if (e[i][j] != '-')
    {
        v[i][e[i][j] - 'a'].push_back(j);
    }
    rep(i, 1, n) f[i][i] = 0;
    rep(i, 1, n) rep(j, 1, n) if (e[i][j] != '-')
    {
        f[i][j] = min(f[i][j], 1);
        for (auto k : v[j][e[i][j] - 'a'])
            f[i][k] = min(f[i][k], 2);
    }
    rep(i, 1, n) rep(j, 1, n) if (f[i][j] != INF) q.push({f[i][j], {i, j}});
    while (!q.empty())
    {
        auto [d, p] = q.top();
        q.pop();
        int x = p.first, y = p.second;
        rep(i, 1, n) if (e[i][x] != '-')
        {
            for (auto j : v[y][e[i][x] - 'a'])
                if (f[i][j] > f[x][y] + 2)
                {
                    f[i][j] = f[x][y] + 2;
                    q.push({f[i][j], {i, j}});
                }
        }
    }
    rep(i, 1, n)
    {
        rep(j, 1, n) if (f[i][j] == INF) cout << -1 << ' ';
        else cout << f[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}