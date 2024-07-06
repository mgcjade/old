#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, d;
int a[N][10];
int mx, mn = INF;
void dfs(int x, int k, int sum)
{
    if (k > d)
    {
        mx = max(mx, sum), mn = min(mn, sum);
        return;
    }
    dfs(x, k + 1, sum + a[x][k]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        dfs(i, 1, 0);
    cout << mx - mn;
    return 0;
}