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

signed main()
{
    int a[10];
    a[5] = 0;
    int f[15];
    rep(i, 1, 4) cin >> a[i], f[a[i]]++;
    sort(a + 1, a + 5);
    int cnt = 0;
    rep(i, 1, 4)
    {
        if (a[i] != a[i - 1])
            cnt++;
        if (cnt > 2)
        {
            cout << "No\n";
            return 0;
        }
        if (f[a[i]] > 3)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}