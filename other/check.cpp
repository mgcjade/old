#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
int n;
int len;
ll ans;
/*
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    len = s.length();
    for (int i = len - 1, j = 1; i >= 0; i--, j <<= 1)
        n += (s[i] == '1') * j;
    rep(i, 0, n) rep(j, 0, n) if ((i ^ j) == (i | j)) cout << i << ' ' << j << ' ' << ++ans << '\n';
    cout << ans << '\n';
    return 0;
}*/
signed main()
{
    fre(test);
    cout << 1;
    rep(i, 1, 1000000) cout << 0;
}