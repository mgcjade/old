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
    int n;
    cin >> n;
    rep(i, 1, n - 1 >> 1) cout << '-';
    if (n & 1)
        cout << '=';
    else
        cout << "==";
    rep(i, 1, n - 1 >> 1) cout << '-';
    return 0;
}