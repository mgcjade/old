#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, d;
int a[N][10];
int ans;
int t;

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
        for (int j = 1; j <= n; j++)
        {
            t = 0;
            for (int k = 1; k <= d; k++)
                t += abs(a[i][k] - a[j][k]);
            ans = max(ans, t);
        }
    cout << ans << '\n';
    return 0;
}