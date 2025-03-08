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

int n, m;
int a[N];
vector<int> e[N];
int ans;

int t[N];
void add(int x, int d)
{
    for (; x <= m; x += x & -x)
        t[x] += d;
}
int get_sum(int x)
{
    int res = 0;
    for (; x; x -= x & -x)
        res += t[x];
    return res;
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> a[i], e[a[i]].push_back(i);
    rep(i, 1, n) add(a[i] + 1, 1), ans += get_sum(m) - get_sum(a[i] + 1);
    cout << ans << '\n';
    memset(t, 0, sizeof(t));
    ref(i, 0, m) for (auto j : e[i]) add(j, 1);
    reb(i, m - 1, 1)
    {
        for (auto j : e[i])
            add(j, -1);
        for (auto j : e[i])
            ans += get_sum(j - 1), ans -= (get_sum(n) - get_sum(j));
        for (auto j : e[i])
            add(j, 1);
        cout << ans << '\n';
    }
}