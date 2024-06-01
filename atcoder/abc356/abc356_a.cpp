#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, l, r;

int main()
{
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        if (i == l)
        {
            i = r;
            while (i >= l)
            {
                cout << i << " ";
                i--;
            }
            i = r;
        }
        else
            cout << i << " ";
    }
    return 0;
}