#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, L;
int c[N], v[N];
bool f[N][N];
bool ans[N];
int m;
int s[N];

int main()
{
    int ti = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> L;
    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i] >> v[i];
        c[i] = min(c[i], L / v[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; ++i)
        cin >> s[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = i; j; --j)
        {
            for (int k = v[i] * c[i]; k; k -= v[i])
                for (int l = L; l >= k; --l)
                    f[j][l] |= f[j - 1][l - k];
            if (ti >= 60000000)
                break;
            ti += n;
        }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= L; ++j)
            ans[j] |= f[s[i]][j];
    for (int i = 1; i <= L; ++i)
        if (ans[i])
            cout << i << ' ';
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << '\n';
    //     for (int j = 1; j <= L; ++j)
    //         cout << f[i][j] << ' ';
    // }
    return 0;
}