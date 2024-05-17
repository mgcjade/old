#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int t, sum;
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    while (n--)
    {
        cin >> t;
        if (sum + t > k)
        {
            ans++;
            sum = 0;
        }
        sum += t;
    }
    ans++;
    cout << ans << '\n';
    return 0;
}