#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

vector<int> pri;
int not_prime[N], phi[N];
void ouler(int n)
{
    phi[1] = 1;
    rep(i, 2, n)
    {
        if (!not_prime[i])
            pri.push_back(i), phi[i] = i - 1;
        for (int pri_j : pri)
        {
            if (i * pri_j > n)
                break;
            not_prime[i * pri_j] = 1;
            if (i % pri_j == 0)
            {
                phi[i * pri_j] = phi[i] * pri_j;
                break;
            }
            phi[i * pri_j] = phi[i] * phi[pri_j];
        }
    }
}
template <class _Tp>
_Tp Pow(_Tp a, _Tp b = MOD - 2, _Tp p = MOD)
{
    _Tp res = 1;
    while (b)
    {
        (b & 1) && (res = (ll)res * a % p);
        a = (ll)a * a % p, b >>= 1;
    }
    return res;
}

int n, k;
void solve()
{
    int ans = 0;
    rep(i, 1, k) ans = (ans + Pow(k / i, n) * phi[i] % MOD) % MOD;
    ans = (ans * Pow(Pow(k, n))) % MOD;
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ouler(1e6);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        solve();
    }
    return 0;
}