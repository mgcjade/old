#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    int ans = 0;
    string str;
    cin >> n;
    while (n--)
    {
        cin >> str;
        if (str == "Takahashi")
            ans++;
    }
    cout << ans;
    return 0;
}