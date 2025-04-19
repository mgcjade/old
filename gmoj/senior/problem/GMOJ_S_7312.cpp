#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 3.3e3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, q;
int a[N + 5];

int cnt;
array<int, 3> b[N * N + 5];
int pre[N + 5];
int fnd(int x) { return x == pre[x] ? x : pre[x] = fnd(pre[x]); }

int cntc;
array<int, 3> c[N + 5];
int ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) rep(j, i + 1, n) b[++cnt] = {a[i] ^ a[j], i, j};
    sort(b + 1, b + cnt + 1);

    rep(i, 1, n) pre[i] = i;
    rep(i, 1, cnt)
    {
        int u = fnd(b[i][1]), v = fnd(b[i][2]);
        if (u != v)
        {
            pre[u] = v;
            c[++cntc] = b[i];
            ans += b[i][0];
        }
    }
    cout << ans << "\n";

    while (q--)
    {
        rep(i, 1, n) pre[i] = i;
        ans = 0;
        array<int, 3> x;
        cin >> x[1] >> x[2] >> x[0];
        x[0] = (a[x[1]] ^ a[x[2]]) & x[0];
        rep(i, 1, cntc)
        {
            if (x[0] < c[i][0])
            {
                int u = fnd(x[1]), v = fnd(x[2]);
                if (u != v)
                {
                    pre[u] = v;
                    ans += x[0];
                }
            }
            int u = fnd(c[i][1]), v = fnd(c[i][2]);
            if (u != v)
            {
                pre[u] = v;
                ans += c[i][0];
            }
        }
        cout << ans << "\n";
    }
    return 0;
}