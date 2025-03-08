#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int fa[N], son[N], len[N];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    fa[0] = 0;
    rep(i, 1, n) cin >> fa[i];
    rep(i, 1, n) len[i] = len[fa[i]] + 1, son[fa[i]]++;
    rep(i, 0, n) if (son[i] == 0) m++;
    while (m--)
    {
        int tmp;
        cin >> tmp;
        while (1)
        {
            if (tmp == 0)
            {
                cout << 0 << '\n';
                break;
            }
            if (son[fa[tmp]] == 1)
            {
                tmp = fa[tmp], son[tmp] = 0;
                continue;
            }
            cout << len[tmp] << '\n';
            son[fa[tmp]]--;
            break;
        }
    }
    return 0;
}
