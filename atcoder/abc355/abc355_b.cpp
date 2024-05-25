#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N], c[N];
bool bz[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[i] = a[i];
        bz[a[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
        c[n + i] = b[i];
    }
    sort(c + 1, c + n + m + 1);
    for (int i = 1; i < n + m; i++)
        if (bz[c[i]] && bz[c[i + 1]])
        {
            cout << "Yes" << "\n";
            return 0;
        }
    cout << "No" << "\n";
    return 0;
}