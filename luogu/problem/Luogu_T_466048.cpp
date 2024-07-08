#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int t[N], p[N];
int ans[N];
int q, T;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        ans[i] = t[i];
    for (int i = 1; i <= n; i++)
        ans[i % n + 1] = min(ans[i % n + 1], ans[i] + p[i]);
    for (int i = 1; i <= n; i++)
        ans[i % n + 1] = min(ans[i % n + 1], ans[i] + p[i]);
    cin >> q;
    while (q--)
    {
        cin >> T;
        cout << ans[T] << '\n';
    }
    return 0;
}