#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
// typedef long long ll;
#define int unsigned int

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, k, mode;
int c[N], t[N];

char ch;
int x, y;

int ans;
map<int, int> cnt;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> mode;
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> t[i];
    while (m--)
    {
        cin >> ch >> x >> y;
        if (mode)
            x ^= ans, y ^= ans;
        if (ch == 'Q')
        {
            ans = 0, cnt.clear();
            rep(i, x, y)
                cnt[t[i]] += c[i];
            for (auto [u, i] : cnt)
            {
                if (k == 1)
                    ans += i;
                else if (k == 2)
                    ans += i * i;
                else
                    ans += i * i * i;
            }
            cout << ans << '\n';
        }
        else if (ch == 'C')
        {
            c[x] = y;
        }
        else
        {
            t[x] = y;
        }
    }
    return 0;
}