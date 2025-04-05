#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 1e9;
const int MOD = 1e9 + 7;

signed main()
{
    int m, n;
    int x = 1, sum = 1;
    cin >> n >> m;
    rep(i, 1, m)
    {
        sum *= n, x += sum;
        if (x > INF)
            return cout << "inf", 0;
    }
    cout << x;
    return 0;
}