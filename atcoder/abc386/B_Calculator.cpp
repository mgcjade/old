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

string str;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    cin >> str;
    ref(i, 0, str.size())
    {
        if (str[i] != '0')
            cnt++;
        else if (str[i] == '0' && str[i + 1] == '0')
            cnt++, i++;
        else
            cnt++;
    }
    cout << cnt << '\n';
}