#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int cnta[N], cntb[N], suma, sumb;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n)
    {
        if (cntb[a[i]] == 0)
            sumb++;
        cntb[a[i]]++;
    }
    int ans = 0;
    ref(i, 1, n)
    {
        if (cnta[a[i]] == 0)
            suma++;
        cnta[a[i]]++;
        if (cntb[a[i]] == 1)
            sumb--;
        cntb[a[i]]--;
        if (suma + sumb >= ans)
        {
            cerr << suma + sumb << ' ' << i << '\n';
        }
        ans = max(ans, suma + sumb);
    }
    cout << ans << endl;
    return 0;
}