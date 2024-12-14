#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1000;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int x[N + 5], y[N + 5];
char ch[N + 5];
pair<int, int> edge[N + 5][N + 5];
int num[N + 5][N + 5];
int turn[128][2];
int ans[N + 5];

int pre[N * N + 5], cnt;
int fnd(int t) { return pre[t] = (pre[t] == t ? t : fnd(pre[t])); }

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
            edge[i][j] = make_pair(0, 0), num[i][j] = ++cnt, pre[cnt] = cnt;
    for (int i = 1; i <= k; i++)
    {
        cin >> x[i] >> y[i] >> ch[i];
        edge[x[i]][y[i]] = make_pair(x[i] + turn[ch[i]][0], y[i] + turn[ch[i]][1]);
    }
    int u, v;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            u = fnd(num[i][j]);
            if (pre[u] == 0)
                continue;
            if (edge[i][j] == make_pair(0, 0))
            {
                v = fnd(num[i - 1][j]);
                if (pre[u] != pre[v])
                    pre[u] = v;
                if (pre[u] == 0)
                    continue;
                v = fnd(num[i + 1][j]);
                if (pre[u] != pre[v])
                    pre[u] = v;
                if (pre[u] == 0)
                    continue;
                v = fnd(num[i][j - 1]);
                if (pre[u] != pre[v])
                    pre[u] = v;
                if (pre[u] == 0)
                    continue;
                v = fnd(num[i][j + 1]);
                if (pre[u] != pre[v])
                    pre[u] = v;
            }
            else
            {
                v = fnd(num[edge[i][j].first][edge[i][j].second]);
                if (pre[u] != pre[v])
                    pre[u] = v;
            }
            cout << i << ' ' << j << '\n';
            for (int i1 = 1; i1 <= n; i1++)
            {
                for (int j1 = 1; j1 <= n; j1++)
                    cout << pre[num[i1][j1]] << ' ';
                cout << '\n';
            }
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ans[k] += (fnd(num[i][j]) != 0);
    cout << ans[k] << '\n';
    // for (int i = 1; i <= k; i++)
    // {
    //     cout << x[i] << ' ' << y[i] << ' ' << edge[x[i]][y[i]].first << ' ' << edge[x[i]][y[i]].second << endl;
    // }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << pre[num[i][j]] << ' ';
        cout << '\n';
    }
    return 0;
}