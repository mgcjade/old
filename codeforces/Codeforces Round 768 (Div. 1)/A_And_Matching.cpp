#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

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
            ref(i, 0, n / 2) cout << i << ' ' << n - i - 1 << '\n';
        }
        else if (k < n - 1)
        {
            cout << 0 << ' ' << n - k - 1 << '\n';
            cout << k << ' ' << n - 1 << '\n';
            int tmp = n / 2;
            ref(i, 1, tmp)
            {
                if (i != k && i != n - k - 1)
                    cout << i << ' ' << n - i - 1 << '\n';
            }
        }
        else
        {
            if (n == 2 || n == 4)
            {
                cout << -1 << '\n';
                continue;
            }
            cout << n - 1 << ' ' << n - 2 << '\n';
            cout << 1 << ' ' << n - 3 << '\n';
            cout << 0 << ' ' << 2 << '\n';
            int tmp = n / 2;
            ref(i, 3, tmp) cout << i << ' ' << n - i - 1 << '\n';
        }
    }
    return 0;
}