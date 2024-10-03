#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    if (n % 4)
        cout << "365";
    else if (n % 100 == 0 && n % 400 != 0)
        cout << "365";
    else
        cout << "366";
    return 0;
}