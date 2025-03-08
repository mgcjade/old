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
    vector<int> a(n);
    ref(i, 0, n) cin >> a[i];
    ref(i, 2, n) if (a[i - 2] == a[i - 1] && a[i - 1] == a[i]) return cout << "Yes", 0;
    cout << "No";
    return 0;
}