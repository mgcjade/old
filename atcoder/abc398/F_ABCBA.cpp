#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int _Tp, PI;
char s[N];

signed main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    ref(i, 1, n)
    {
        if (s[i] != s[n])
            continue;
        _Tp = 0;
        for (int j = i, k = n; j <= k; j++, k--)
            if (s[j] != s[k])
            {
                _Tp = 1;
                break;
            }
        if (!_Tp)
        {
            PI = i - 1;
            if (!PI)
                PI = -1;
            break;
        }
    }
    if (!PI)
        PI = n - 1;
    cout << s + 1;
    reb(i, PI, 1) cout << s[i];
    return 0;
}