#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int lst;
int t, v;
int h2o;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> v;
        h2o = h2o - (t - lst);
        h2o = max(h2o, 0);
        h2o += v;
        lst = t;
    }
    cout << h2o << '\n';
    return 0;
}