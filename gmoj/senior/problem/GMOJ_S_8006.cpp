#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int p[N], w[N];

bool vis[N];
pair<int, int> pr[N];
int tot;

int main()
{
    // fre(garrison);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 2; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            continue;
        int j = i, mx = 0;
        while (!vis[j])
        {
            mx = max(mx, j);
            vis[j] = 1;
            ans += abs(p[j] - p[w[j]]);
            j = w[j];
        }
        pr[++tot] = make_pair(i, mx);
    }
    sort(pr + 1, pr + tot + 1);
    int mx = 0;
    for (int i = 1; i <= tot; i++)
    {
        if (pr[i].first == pr[i].second)
            continue;
        if (pr[i].first > mx)
            ans += 2 * abs(p[pr[i].first] - p[mx]);
        mx = max(mx, pr[i].second);
        // cout << pr[i].first << ' ' << pr[i].second << ' ' << mx << ' ' << ans << '\n';
    }
    cout << ans << '\n';
    return 0;
}