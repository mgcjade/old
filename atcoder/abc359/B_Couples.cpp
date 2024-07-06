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
    int a[105];
    cin >> n;
    n *= 2;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i < n; i++)
        if (a[i - 1] == a[i + 1])
            ans++;
    cout << ans << endl;
    return 0;
}