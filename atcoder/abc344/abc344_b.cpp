#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int a[1005], tot = 0;
    int t;
    while (cin >> t)
        a[++tot] = t;
    while (tot--)
        cout << a[tot + 1] << '\n';
    return 0;
}