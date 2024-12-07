#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int k;
string str[15];
int a[15][15];
int ans;
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> str[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = str[i][j - 1] == '.' ? 1 : 0;
    for (int i1 = 1; i1 <= n; i1++)
        for (int j1 = 1; j1 <= m; j1++)
            for (int i2 = 1; i2 <= n; i2++)
                for (int j2 = 1; j2 <= m; j2++)
                    if ((i1 != i2 || j1 != j2) && a[i1][j1] && a[i2][j2])
                    {
                        cnt = 0;
                        for (int i = 1; i <= n; i++)
                            for (int j = 1; j <= m; j++)
                                if (a[i][j] && (abs(i - i1) + abs(j - j1) <= k || abs(i - i2) + abs(j - j2) <= k))
                                    cnt++;
                        ans = max(ans, cnt);
                    }
    cout << ans;
    return 0;
}