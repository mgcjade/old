#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;    
    int c, gcd, lcm;
    for (int i = n; i <= (n << 1); i++)
    {
        lcm =  n * i /  __gcd(n, i);
        c = lcm / n - lcm / i;
        gcd = __gcd(n, c);
        if (gcd == c)
            ans++;
    }
    cout << ans << '\n';
    return 0;
}