#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, l;
int a[105], b[105], c[105];
int T, q;
map<int, bool> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    cin >> l;
    for (int k = 1; k <= l; k++)
        cin >> c[k];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= l; k++)
                mp[a[i] + b[j] + c[k]] = 1;
    cin >> T;
    while (T--)
    {
        cin >> q;
        if (mp[q] == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}