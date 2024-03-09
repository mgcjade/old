#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int op, x;
int f[N], a[N], tot[N];

int main()
{
    fre(ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int tp = 1; tp <= n; tp++)
    {
        cin >> op >> x;
        if (op == 0)
        {
            tot[tp] = tot[tp - 1] + 1;
            a[tot[tp]] = x;
            f[tot[tp]] = 1;
            for (int i = 1; i < tot[tp]; i++)
                f[tot[tp]] = max(f[tot[tp]], f[i] + (a[tot[tp]] > a[i]));
        }
        else
        {
            tot[tp] = tot[x];
        }
        cout << f[tot[tp]] << '\n';
    }
    return 0;
}