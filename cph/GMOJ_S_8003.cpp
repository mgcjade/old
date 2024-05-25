#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int a[N], len[N];
int pw[5];
int ans;

int main()
{
    // fre(piece);
    pw[0] = 1e0, pw[1] = 1e1, pw[2] = 1e2, pw[3] = 1e3, pw[4] = 1e4;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        while (x)
        {
            ++len[i];
            x /= 10;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && (a[i] * pw[len[j]] + a[j]) % k != 0)
                ans++;
    cout << ans << "\n";
    return 0;
}