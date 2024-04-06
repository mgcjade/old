#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, p;
int f[N + 5][35];
int ans;
bool check(int a, int b)
{
    int s = a & b, t = a | b;
    for (int i = 1; i < m; i++)
    {
        if ((s & 3) == 3 || (t & 3) == 0)
            return 0;
        s >>= 1, t >>= 1;
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> p;
    int s = (1 << m);
    for (int j = 0; j < s; j++)
        f[1][j] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 0; j < s; j++)
            for (int k = 0; k < s; k++)
                if (check(j, k))
                    f[i][j] = (f[i][j] + f[i - 1][k]) % p;
    for (int i = 0; i < s; i++)
        ans = (ans + f[n][i]) % p;
    cout << ans << '\n';
    return 0;
}