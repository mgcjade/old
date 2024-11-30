#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    if (a == b)
        ans++, a = -1, b = -2;
    if (a == c)
        ans++, a = -1, c = -3;
    if (a == d)
        ans++, a = -1, d = -4;
    if (b == c)
        ans++, b = -2, c = -3;
    if (b == d)
        ans++, b = -2, d = -4;
    if (c == d)
        ans++, c = -3, d = -4;
    cout << ans << '\n';
    return 0;
}