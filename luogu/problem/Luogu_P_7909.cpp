#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    if (a + n <= b || a % n > b % n)
        cout << n - 1 << '\n';
    else
        cout << b % n << '\n';
    return 0;
}