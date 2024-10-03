#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, a, b;

int main()
{
    cin >> n >> a >> b;
    if (a + (n - a - b) < b || b + (n - a - b) < a)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}