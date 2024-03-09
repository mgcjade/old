#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    freopen("ysf14.in", "w", stdout);
    mt19937 rd(time(0) * time(0));
    cout << rd() % 99991 + 10 << ' ' << rd() % 95 + 6;
    return 0;
}