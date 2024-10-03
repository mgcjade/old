#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int len;
string str;
int a[N], b[N];
int c[N];
int l[N], r[N];
int sum[N];
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> str;
        len = str.size();
        for (int i = 1; i <= len; i++)
            a[i] = 0, b[i] = 0;
        c[0] = 0;
        for (int i = 1; i <= len; i++)
        {
            if (str[i - 1] == '(')
            {
                c[0]++;
                c[c[0]] = i;
            }
            else
            {
                if (c[0])
                {
                    b[c[c[0]]] = i + 1;
                    a[i + 1] = c[c[0]];
                    c[0]--;
                }
            }
        }
        for (int i = 1; i <= len; i++)
            l[i] = l[a[i]] - 1;
        for (int i = len + 1; i; i--)
            r[i] = r[b[i]] + 1;
        ans = 0;
        for (int i = 1; i <= len; i++)
        {
            sum[i] = sum[i - 1] + l[i] + r[i];
            ans += (sum[i] * i) % MOD;
        }
        cout << ans << '\n';
    }
    return 0;
}