#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e2;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[(N << 1) + 5];
int f[(N << 1) + 5][(N << 1) + 5];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int len = 1; len <= n; len++)
        for (int st = 1, en = st + len; en <= (n << 1); st++, en++)
            for (int k = st + 1; k < en; k++)
                f[st][en] = max(f[st][en], f[st][k] + f[k][en] + a[st] * a[k] * a[en]);
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i][i + n]);
    cout << ans << '\n';
    return 0;
}