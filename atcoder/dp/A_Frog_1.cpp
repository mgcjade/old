#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;

int n;
int h[N], dp[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    dp[0] = 0x3f3f3f3f;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    cout << dp[n];
    return 0;
}