#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int a[N];
pair<int, int> b[N];
int f[N];
int ans;
vector<int> edge[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i].first = a[i];
        b[i].second = i;
    }
    sort(b, b + n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n && b[j].first - b[i].first <= k; j++)
        {
            edge[b[i].second].push_back(b[j].second), edge[b[j].second].push_back(b[i].second);
            break;
        }
    for (int i = 1; i <= n; i++)
    {
        f[i] = max(f[i], 1);
        int len = edge[i].size();
        for (int j = 0; j < len; j++)
            f[edge[i][j]] = max(f[edge[i][j]], f[i] + 1);
        ans = max(ans, f[i]);
    }
    cout << ans;
    return 0;
}