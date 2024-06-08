#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int vis[N];
int nxt[N], cnt[N];
int ans[N];
ll sum;

int dfs(int k)
{
    if (vis[k])
        return cnt[k];
    vis[k] = 1;
    cnt[k] = dfs(nxt[k]) + 1;
    return cnt[k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        nxt[i] = a[i], cnt[i] = 1;
        sum += dfs(a[i]);
    }
    cout << sum;
    return 0;
}