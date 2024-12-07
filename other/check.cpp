#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int a, b;
int ans;
int t;

int main()
{
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        t = sqrt(i);
        if (t * t + t >= i)
        {
            if (t & 1)
                ans += i;
            else
                ans -= i;
        }
        else
        {
            if (t & 1)
                ans -= i;
            else
                ans += i;
        }
        ans = (ans % MOD + MOD) % MOD;
        cout << ans << ' ' << i << '\n';
    }
    return 0;
}