#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n, m, k;
int a[N];
int x[N], y[N];
int suma, sumb;
int cnta, cntb;
int flag;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cnta = cntb = 0, suma = sumb = 0, flag = 0;
        cin >> n >> m >> k;
        rep(i, 1, k) cin >> a[i];
        rep(i, 1, k) x[i] = a[i] / n, y[i] = a[i] / m;
        sort(x + 1, x + k + 1), sort(y + 1, y + k + 1);

        int i = 1, j = k;
        while (i <= j && x[i] < 2)
            i++;
        while (i <= j && cnta + 2 <= m)
        {
            cnta += 2, suma += x[j] - 2, j--;
            if (cnta + suma >= m)
            {
                flag = 1;
                break;
            }
        }

        i = 1, j = k;
        while (i <= j && y[i] < 2)
            i++;
        while (i <= j && cntb + 2 <= n)
        {
            cntb += 2, sumb += y[j] - 2, j--;
            if (cntb + sumb >= n)
            {
                flag = 1;
                break;
            }
        }

        if (flag)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}