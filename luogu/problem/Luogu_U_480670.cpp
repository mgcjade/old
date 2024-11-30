#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n, k;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        if (k == 0)
        {
            cout << 1 << '\n';
            continue;
        }
        cout << (n / k) - (n / (k + 1)) << '\n';
        // cout << (n / k) - (int)(ceil(n / 1.0 / (k + 1)) - 1) << '\n';
    }
    return 0;
}