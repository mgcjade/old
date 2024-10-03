#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int m;
int ans[25], n;

int main()
{
    cin >> m;
    for (int i = 0; m; i++)
    {
        ans[i] += m % 3;
        n += m % 3;
        m /= 3;
    }
    cout << n << '\n';
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 1; j <= ans[i]; j++)
            cout << i << ' ';
    }
    return 0;
}