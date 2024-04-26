#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
ull a[N], b[N];

int main()
{
    // freopen("shuffle.in", "r", stdin);
    // freopen("shuffle.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    ull u, v;
    for (int i = 2; i <= n; i++)
    {
        u = a[i - 1] * a[i] + b[i - 1] * b[i];
        v = a[i - 1] * b[i] - a[i] * b[i - 1];
        a[i] = u, b[i] = v;
    }
    cout << a[n] << ' ' << b[n] << '\n';
    return 0;
}