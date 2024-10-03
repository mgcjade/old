#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int ans;
int l = 1, r;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[1], a[n + 1] = a[n];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != a[i - 1] && a[i] != a[i + 1])
            r = i + 1;
        else
        {
            ans = max(ans, (r - l) / 2);
            for (int x = l + 1, y = r - 1; x <= y; x++, y--)
                a[x] = a[l], a[y] = a[r];
            l = i, r = i;
        }
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';
    return 0;
}