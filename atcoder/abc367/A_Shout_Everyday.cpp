#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    for (int i = b; i != c; i = (i + 1) % 24)
        if (i == a)
        {
            cout << "No";
            return 0;
        }
    if (a == b || a == c)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}