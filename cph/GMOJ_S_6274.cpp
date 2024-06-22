#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
pair<int, int> p[N];
int t[N];
int ans;
int x, y;

class cmp
{
public:
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> p[i].first >> p[i].second;
    sort(p + 1, p + n + 1);
    for (int j = 1; j <= m; j++)
        cin >> t[j];
    sort(t + 1, t + m + 1);
    x = 1, y = 1;
    while ((x <= n || !q.empty()) && y <= m)
    {
        if (x <= n && p[x].first <= t[y])
        {
            q.push(make_pair(p[x].first, p[x].second));
            x++;
        }
        while (!q.empty() && q.top().second < t[y])
            q.pop();
        if (!q.empty() && q.top().first <= t[y] && q.top().second >= t[y])
        {
            cout << q.top().first << " " << q.top().second << ' ' << t[y] << '\n';
            ans++;
            q.pop();
            y++;
        }
        else if (q.empty())
            y++;
    }
    cout << ans << '\n';
    return 0;
}