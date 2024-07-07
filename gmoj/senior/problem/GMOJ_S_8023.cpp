#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, l;
int s[N], tot = 1;
int v[N], c[N];
bool f[N][N];
int ans[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
        cin >> c[i] >> v[i];
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> s[i];
    sort(s + 1, s + m + 1);
    f[0][0] = 1;
    for (int j = 1; j <= n; j++)
        for (int k = 1; k <= n; k++)
            for (int h = c[k]; h; h--)
                for (int i = l; i >= h * v[k]; i--)
                    f[j][i] |= f[j][i - h * v[k]] | f[j - 1][i - h * v[k]];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= l; j++)
            ans[j] |= f[s[i]][j];
    for (int i = 1; i <= l; i++)
        if (ans[i])
            cout << i << ' ';
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << '\n';
    //     for (int j = 1; j <= l; j++)
    //         cout << f[i][j] << ' ';
    // }
    return 0;
}