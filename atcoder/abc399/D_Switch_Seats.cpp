#include <bits/stdc++.h>
#define fre(u) freopen(#u ".in", "r", stdin), freopen(#u ".out", "w", stdout)
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
int val[N][2];
int ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n;
        m = n << 1, ans = 0;
        rep(i, 1, m) cin >> a[i], val[a[i]][0] = val[a[i]][1] = 0;
        rep(i, 1, m) if (val[a[i]][0]) val[a[i]][1] = i;
        else val[a[i]][0] = i;
        a[m + 1] = -1;
        rep(i, 1, n)
        {
            if (val[i][0] + 1 == val[i][1])
                continue;
            int u[] = {a[val[i][0] + 1], a[val[i][0] - 1], a[val[i][1] + 1], a[val[i][1] - 1]}, v[] = {val[i][0] + 1, val[i][0] - 1, val[i][1] + 1, val[i][1] - 1};
            ref(j, 0, 2) ref(k, 2, 4) if (u[j] == u[k] && v[j] != v[k]) ans -= (j == 1 && k == 2 && val[i][0] + 1 == val[i][1]) + (j == 0 && k == 3 && val[i][0] + 3 == val[i][1]) - 1;
        }
        cout << (ans >> 1) << '\n';
    }
    return 0;
}