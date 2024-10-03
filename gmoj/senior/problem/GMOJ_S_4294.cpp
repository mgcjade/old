#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, q;
int x[N], y[N], z[N];
char c[N], ans[205], ch;
int len = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> c + 1;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        x[i]++;
        z[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        for (int j = q; j >= 1; j--)
        {
            if (z[j] <= t && t <= z[j] + (y[j] - x[j]))
                t = x[j] + (t - z[j]);
            else if (t > z[j] + y[j] - x[j])
                t -= (y[j] - x[j] + 1);
        }
        ans[i] = c[t];
    }
    cout << ans + 1;
    return 0;
}