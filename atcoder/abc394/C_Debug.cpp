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
string str;

signed main()
{
    cin >> str;
    n = str.length();
    reb(i, n - 2, 0) if (str[i] == 'W' && str[i + 1] == 'A') str[i] = 'A', str[i + 1] = 'C';
    cout << str;
    return 0;
}