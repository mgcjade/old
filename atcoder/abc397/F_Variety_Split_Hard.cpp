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

int n;
int mx[N]; // 前缀数组
int a[N];
int cnta[N], cntb[N], suma, sumb;
int ans;

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    int k = 1;
    cnta[a[1]]++, suma = 1, cntb[a[2]]++, sumb = 1;
    mx[1] = 0, mx[2] = 2;
    rep(i, 3, n)
    {
        mx[i] = mx[i - 1];
        cntb[a[i]]++;
        if (cntb[a[i]] == 1)
            sumb++;
        while (cnta[a[k + 1]] == 0 || cntb[a[k + 1]] > 1)
        {
            k++;
            cnta[a[k]]++;
            if (cnta[a[k]] == 1)
                suma++;
            cntb[a[k]]--;
            if (cntb[a[k]] == 0)
                sumb--;
            mx[i] = max(mx[i], sumb + suma);
        }
        mx[i] = max(mx[i], sumb + suma);
    }
    memset(cnta, 0, sizeof(cnta));
    suma = 0;
    rep(i, 3, n)
    {
        cnta[a[i]]++;
        if (cnta[a[i]] == 1)
            suma++;
    }
    rep(i, 3, n)
    {
        ans = max(ans, mx[i - 1] + suma);
        cnta[a[i]]--;
        if (cnta[a[i]] == 0)
            suma--;
    }
    cout << ans << '\n';
    return 0;
}