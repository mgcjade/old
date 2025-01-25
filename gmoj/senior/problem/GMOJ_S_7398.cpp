#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 5005;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int mx[N];
int a[N][N];
int l, r, x;
int bz[N];
int dif;
int tmp;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) cin >> mx[i];
    while (m--)
    {
        cin >> l >> r >> x;
        if (bz[x] == 0)
            dif++;
        bz[x] += r - l + 1;
        rep(i, l, r)
        {
            a[i][++a[i][0]] = x;
            if (a[i][0] > mx[i])
            {
                tmp = a[i][a[i][0] - mx[i]];
                bz[tmp]--;
                if (bz[tmp] == 0)
                    dif--;
            }
        }
        cout << dif << '\n';
    }
    return 0;
}