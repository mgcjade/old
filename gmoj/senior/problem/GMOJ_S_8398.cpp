#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int u, v;
int dis[N], cnt[N];
int f, z;
char c;
vector<pair<int, int>> g[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> u >> v >> c;
        if (c == '(')
            g[u].push_back({v, 1});
        else
            g[u].push_back({v, -1});
    }
    queue<int> q;
    q.push(1);
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (cnt[a] >= n)
        {
            f = 1;
            break;
        }
        for (auto v : g[a])
            if (dis[v.first] > dis[a] + v.second)
                dis[v.first] = dis[a] + v.second, q.push(v.first), cnt[v.first]++;
    }
    while (!q.empty())
        q.pop();
    q.push(1);
    memset(dis, 0x80, sizeof(dis));
    memset(cnt, 0, sizeof(cnt));
    dis[1] = 0;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        if (cnt[a] >= n)
        {
            z = 1;
            break;
        }
        for (auto v : g[a])
            if (dis[v.first] < dis[a] + v.second)
                dis[v.first] = dis[a] + v.second, q.push(v.first), cnt[v.first]++;
    }
    if (f && z)
        cout << "Yes\n";
    else if (f || z)
        cout << "No\n";
    else
        cout << "Yes\n";
}