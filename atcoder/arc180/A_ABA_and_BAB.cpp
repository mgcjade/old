#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2.5e5 + 5;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int len;
string str;
int cnt = 1;
ll ans = 1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> len;
    cin >> str;
    for (int i = 1; i < len; i++)
    {
        if (str[i] != str[i - 1])
            cnt++;
        else
        {
            if (cnt >= 3)
                ans = ans * ((cnt - 1) / 2 + 1) % MOD;
            cnt = 1;
        }
    }
    if (cnt >= 3)
        ans = ans * ((cnt - 1) / 2 + 1) % MOD;
    cout << ans << '\n';
    return 0;
}