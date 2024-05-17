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
    int a[105];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[1])
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}