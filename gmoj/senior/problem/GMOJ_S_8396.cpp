#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long
inline int lg(int x) { return x ? __lg(x) : -1; }

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int solve(int l, int r)
{
    if (l == r)
        return 1;
    int cut, res;
    cut = lg(l ^ r);
    int full = (1ll << cut) - 1;
    res = full - (full & l) + 1;
    int A = l & full, B = r & full;
    if (lg(A) > lg(B))
        res += (1ll << lg(B) + 1) + res;
    else
        res += full + 1;
    return res;
}

int T;
int l, r;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> l >> r;
        cout << solve(l, r) << '\n';
    }
    return 0;
}