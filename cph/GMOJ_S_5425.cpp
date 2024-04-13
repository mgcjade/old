#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, m, p;
int ans;

int main()
{
    // fre(math);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> p;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         ans = (ans + min(n / i, m / j) * (__gcd(i, j) == 1)) % p;
    cout << n * m % p << '\n';
    return 0;
}