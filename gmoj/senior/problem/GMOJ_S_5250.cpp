#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 998244353;

int n;
int ans;
int sum(int k)
{
    int ret = 0;
    if (k % 2 == 0)
        ret++;
    while (k % 2 == 0)
        k /= 2;
    for (int i = 3; i <= k; i += 2)
    {
        if (k % i == 0)
            ret++;
        while (k % i == 0)
            k /= i;
    }
    return ret;
}

int fastpow(int a, int b)
{
    int ret = 1;
    while (b)
    {
        if (b & 1)
            ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        ans = (ans + fastpow(2, sum(i))) % MOD;
    cout << ans;
    return 0;
}
