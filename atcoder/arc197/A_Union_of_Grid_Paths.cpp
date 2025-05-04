#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
string s;
int h, w;
int a, b;
int ans, cnt;

void solve()
{
    cin >> h >> w;
    n = h + w - 2;
    cin >> s;
    ans = 1, cnt = 1;
    a = 0, b = 0;
    s = " " + s;
    rep(i, 1, n) if (s[i] == 'D') a++;
    else if (s[i] == 'R') b++;
    a = h - a - 1, b = w - b - 1;
    rep(i, 1, n)
    {
        if (s[i] == '?')
        {
            a--, b--, cnt++;
            if (a < 0)
                cnt--, a++;
            if (b < 0)
                cnt--, b++;
        }
        ans += cnt;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}