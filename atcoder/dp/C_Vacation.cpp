#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
int a[N], b[N], c[N];
int dp[N][5];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i] >> c[i];
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]) + a[i];
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][3]) + b[i];
        dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + c[i];
    }
    cout << max(max(dp[n][1], dp[n][2]), dp[n][3]);
    return 0;
}