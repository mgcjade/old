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

int st[500], hd = 100;
int Q;
int flag, x;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> Q;
    while (Q--)
    {
        cin >> flag;
        if (flag == 1)
        {
            cin >> x;
            st[++hd] = x;
        }
        else
        {
            cout << st[hd] << '\n';
            hd--;
        }
    }
    return 0;
}