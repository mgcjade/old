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
    int mx = 0, q = 0, cmx = 0, w = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > mx)
        {
            cmx = mx;
            w = q;
            mx = a[i];
            q = i;
        }
        else if (a[i] > cmx)
        {
            cmx = a[i];
            w = i;
        }
    }
    cout << w << endl;
    return 0;
}