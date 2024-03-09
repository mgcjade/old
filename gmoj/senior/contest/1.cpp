#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
double v;
double x, y, ans;

int main()
{
    fre(ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v;
        ans = ans + (3 * y + 3 * x + 1) * v;
        y = (y + 2 * x + 1) * v;
        x = (x + 1) * v;
    }
    cout << fixed << setprecision(1) << ans;
    return 0;
}