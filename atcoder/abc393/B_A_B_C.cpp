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

signed main()
{
    string str;
    int ans = 0;
    cin >> str;
    int len = str.size();
    ref(i, 0, len) ref(j, i + 1, len) ref(k, j + 1, len) if (str[i] == 'A' && str[j] == 'B' && str[k] == 'C' && j - i == k - j) ans++;
    cout << ans << '\n';
    return 0;
}