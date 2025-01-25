#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N];
int f[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i];
        f[n] = 1;
        reb(i, n - 1, 1)
        {
            if (a[i] <= f[i + 1])
                f[i] = f[i + 1];
            else
                f[i] = f[i + 1] + 1;
        }
        rep(i, 1, n)
        {
            if (f[i] <= m)
                cout << 1;
            else if (a[i] <= m)
                cout << 1;
            else
                cout << 0;
        }
        cout << '\n';
    }
    return 0;
}