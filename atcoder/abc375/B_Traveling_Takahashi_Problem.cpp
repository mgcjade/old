#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
double ans;
double a, b, c, d;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    while (n--)
    {
        cin >> c >> d;
        ans += sqrt((a - c) * (a - c) + (b - d) * (b - d));
        a = c, b = d;
    }
    ans += sqrt(a * a + b * b);
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}