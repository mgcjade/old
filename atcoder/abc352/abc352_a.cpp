#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, x, y, z;

int main()
{
    cin >> n >> x >> y >> z;
    if (x > y)
        swap(x, y);
    if (x <= z && z <= y)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}