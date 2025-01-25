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

int T;
int n;
int a[N];
int k, cnt;

signed main()
{
    cin >> T;
    while (T--)
    {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        sort(a + 1, a + n + 1, greater<int>());
        k = n, cnt = 0;
        while (k > 1 && a[k] == 0)
            k--, cnt++;
        ref(i, 1, n)
        {
            ref(i, 1, k) a[i] = a[i] - a[i + 1];
            if (!cnt)
                a[k] = 0;
            sort(a + 1, a + k + 1, greater<int>());
            while (k > 1 && a[k] == 0)
                k--, cnt++;
            cnt--;
        }
        cout << a[1] << '\n';
    }
    return 0;
}