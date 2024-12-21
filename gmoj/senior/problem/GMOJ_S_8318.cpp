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

int n, m;
int a[N];
int b[N];
int cnt[5];
ll mx, mn;
struct node
{
    int p;
    int x;
    int num;
} ask[N];
bool cmp(node x, node y) { return x.p == y.p ? x.x < y.x : x.p < y.p; }
ll ans[N];
ll now;

int main()
{
    memset(ans, -1, sizeof(ans));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n)
    {
        cin >> a[i];
        ++cnt[a[i]];
        now += cnt[1] * cnt[1];
    }
    rep(i, 1, cnt[1])
    {
        mn = mn + i * i;
    }
    mx = mn + cnt[1] * cnt[1] * cnt[0];
    // cout << mn << ' ' << mx << ' ' << now << '\n';
    rep(i, 1, m)
    {
        cin >> ask[i].p >> ask[i].x;
        ask[i].num = i;
    }
    sort(ask + 1, ask + m + 1, cmp);
    int l = 1, r = m;
    rep(i, 1, m)
    {
        if (ask[i].p == 2)
        {
            r = min(r, i);
            break;
        }
        if (ask[i].x < mn)
        {
            l = i;
            ans[ask[i].num] = -1;
        }
        if (ask[i].x >= now)
        {
            r = min(r, i - 1);
            ans[ask[i].num] = 0;
        }
    }
    // cout << l << ' ' << r << '\n';
    // rep(i, 1, m)
    // {
    //     cout << ask[i].p << ' ' << ask[i].x << ' ' << ask[i].num << '\n';
    // }
    memcpy(b + 1, a + 1, sizeof(int) * n);
    int t = cnt[1];
    reb(i, r, l)
    {
        }
    rep(i, 1, m)
    {
        cout << ans[i] << '\n';
    }
    return 0;
}