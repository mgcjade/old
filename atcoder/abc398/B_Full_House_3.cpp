#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

signed main()
{
    int a, b, c, d, e, f, g;
    cin >> a >> b >> c >> d >> e >> f >> g;
    int cnt[15];
    memset(cnt, 0, sizeof(cnt));
    cnt[a]++, cnt[b]++, cnt[c]++, cnt[d]++, cnt[e]++, cnt[f]++, cnt[g]++;
    int flag = 0;
    rep(i, 1, 13) if (cnt[i] >= 3)
    {
        flag = 1;
        cnt[i] = 0;
        break;
    }
    if (!flag)
        return cout << "No\n", 0;
    rep(i, 1, 13) if (cnt[i] >= 2)
    {
        cout << "Yes\n";
        return 0;
    }
    cout << "No\n";
    return 0;
}