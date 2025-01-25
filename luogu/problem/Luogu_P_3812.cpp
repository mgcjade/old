#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
// typedef long long ll;
#define int unsigned long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int b[N];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) b[i] = a[i];
    int k = 1;
    reb(i, 60, 0)
    {
        rep(j, k, n) if (b[j] & (1ull << i))
        {
            swap(b[j], b[k]);
            break;
        }
        if (b[k] & (1ull << i))
        {
            rep(j, 1, n) if (j != k && (b[j] & (1ull << i))) b[j] ^= b[k];
            k++;
        }
        if (k == n)
            break;
    }
    int ans = 0;
    rep(i, 1, k) ans = max(ans, ans ^ b[i]);
    cout << ans << '\n';
    return 0;
}