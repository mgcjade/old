#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < n - 2; i++)
        if (str[i] == '#' && str[i + 1] == '.' && str[i + 2] == '#')
            ans++;
    cout << ans << '\n';
    return 0;
}