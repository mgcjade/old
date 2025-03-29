#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

vector<vector<int>> solve(int max_m)
{
    vector<vector<int>> c(max_m + 1, vector<int>(max_m + 1, 0));
    rep(i, 0, max_m)
    {
        c[i][0] = 1;
        if (i > 0)
            c[i][i] = 1;
        ref(j, 1, i) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
    }
    return c;
}

int n, k;
int ans;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, x = (x % MOD + MOD) % MOD;
    auto c = solve(k);
    vector<int> b(k + 1, 0);
    for (int x : a)
    {
        vector<int> d(k + 1), e(k + 1, 0);
        d[0] = 1;
        rep(i, 1, k) d[i] = d[i - 1] * x % MOD;
        rep(i, 0, k)
        {
            e[i] = d[i];
            rep(j, 0, i) e[i] = (e[i] + c[i][j] * b[j] % MOD * d[i - j]) % MOD;
        }
        ans = (ans + e[k]) % MOD;
        b = e;
    }
    cout << ans << '\n';
    return 0;
}
