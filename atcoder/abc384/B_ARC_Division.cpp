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
    int n, sum, a, b;
    cin >> n >> sum;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (a == 2 && sum <= 2399 && sum >= 1200)
            sum += b;
        if (a == 1 && sum <= 2799 && sum >= 1600)
            sum += b;
    }
    cout << sum;
    return 0;
}