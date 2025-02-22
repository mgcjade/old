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
pair<int, string> str[55];

signed main()
{
    cin >> n;
    rep(i, 1, n) cin >> str[i].second;
    rep(i, 1, n) str[i].first = str[i].second.length();
    sort(str + 1, str + n + 1);
    rep(i, 1, n) cout << str[i].second;
    return 0;
}