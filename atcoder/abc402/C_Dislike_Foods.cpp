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

int n, m;
int a[N];
vector<int> sc[N];
int x;

signed main()
{
    cin >> n >> m;
    rep(i, 1, m)
    {
        cin >> a[i];
        rep(j, 1, a[i])
        {
            cin >> x;
            sc[x].push_back(i);
        }
    }
    int ans = 0;
    rep(i, 1, n)
    {
        cin >> x;
        for (auto j : sc[x])
        {
            a[j]--;
            if (a[j] == 0)
                ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}