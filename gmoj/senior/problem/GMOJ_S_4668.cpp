#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 3e4 + 5;
const int INF = 0x3f3f3f3f;
const __int128 MOD = 1e11 + 9;

int n;
ll a[N];
ll pri[1000005][30];
__int128 ans = 1;
int mx;
ll fastpow(__int128 x, __int128 y)
{
    __int128 ret = 1;
    while (y)
    {
        if (y & 1)
            ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        y >>= 1;
    }
    return ret;
}

int prim[10000005], prime[10000000], cnt;
void init()
{
    int MAX = 1e7;
    for (int i = 2; i <= MAX; i++)
    {
        if (!prim[i])
            prime[++cnt] = i;
        int t = MAX / i;
        for (int j = 1; prime[j] <= t && j <= cnt; j++)
        {
            prim[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
    for (int i = 1; i <= cnt; i++)
        prim[prime[i]] = i;
    return;
}

int main()
{
    // fre(ans);
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        ans = (ans * a[i]) % MOD;
        ll t = sqrt(a[i]);
        for (int j = 2; j <= a[i] && j <= t; j++)
        {
            mx = max(mx, prim[j]);
            for (int k = 1; a[i] % j == 0; k++)
            {
                a[i] /= j;
                pri[prim[j]][k]++;
            }
        }
        if (a[i] > 1)
            pri[prim[a[i]]][1]++;
    }
    for (int i = 1; i <= mx; i++)
    {
        // cout << ans << '\n';
        for (int j = 1; pri[i][j] > 0; j++)
            ans = (ans * fastpow(prime[i], pri[i][j] * (pri[i][j] - 1) / 2)) % MOD;
    }
    cout << (ll)ans << '\n';
    return 0;
}