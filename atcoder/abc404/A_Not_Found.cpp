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

string str;
int cnt[26];

signed main()
{
    cin >> str;
    ref(i, 0, str.size()) cnt[str[i] - 'a']++;
    rep(i, 0, 25) if (cnt[i] == 0) return cout << char(i + 'a'), 0;
    return 0;
}