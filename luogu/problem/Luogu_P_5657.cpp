#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    unsigned long long n, k;
    cin >> n >> k;
    k = k ^ k >> 1;
    while (n--)
        cout << (k >> n & 1);
    return 0;
}