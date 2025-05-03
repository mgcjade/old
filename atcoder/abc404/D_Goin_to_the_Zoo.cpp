#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 12;
const int INF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int fee[N];
int cnt[105];

int ans = INF;

vector<int> a[N];

void dg(int x, int pay)
{
    if (x > n)
    {
        rep(i, 1, m) if (cnt[i] < 2) return;
        ans = min(ans, pay);
        return;
    }
    dg(x + 1, pay);
    for (auto i : a[x])
        cnt[i]++;
    dg(x + 1, pay + fee[x]);
    for (auto i : a[x])
        cnt[i]++;
    dg(x + 1, pay + 2 * fee[x]);
    for (auto i : a[x])
        cnt[i] -= 2;
}

signed main()
{
    cin >> n >> m;
    rep(i, 1, n) cin >> fee[i];
    int k, x;
    rep(i, 1, m)
    {
        cin >> k;
        rep(j, 1, k)
        {
            cin >> x;
            a[x].push_back(i);
        }
    }
    dg(1, 0);
    cout << ans << '\n';
    return 0;
}