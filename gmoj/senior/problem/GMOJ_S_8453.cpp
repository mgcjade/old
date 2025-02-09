#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int unsigned long long

const int N = 3e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int K = 37;

char str[N];
int n, cnt, T;
int f[N], b[N];
struct node
{
    int l, r;
} q[N];
int ans[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> str + 1)
    {
        cout << "Case " << ++T << ": ";
        ref(i, 0, n)
            ans[i] = false;
        n = strlen(str + 1);
        rep(i, 1, n)
            str[n + i] = str[i];
        int m = n * 2, Ls = 1;
        cnt = 0;
        ref(i, 1, m) if (str[i] == str[i + 1])
        {
            q[++cnt] = {Ls, i};
            Ls = i + 1;
        }
        q[++cnt] = {Ls, m};
        rep(i, 1, cnt)
        {
            rep(j, q[i].l, q[i].r)
                f[j - q[i].l + 1] = f[j - q[i].l] * K + (str[j] - 'a' + 7);
            int pre = 1;
            reb(j, q[i].r, q[i].l)
            {
                b[q[i].r - j + 1] = b[q[i].r - j] + (str[j] - 'a' + 7) * pre;
                pre = pre * K;
            }
            rep(k, 1, q[i].r - q[i].l + 1)
            {
                if (k > n)
                    break;
                if (f[q[i].r - q[i].l + 1 - (k - 1)] != b[q[i].r - q[i].l + 1 - (k - 1)])
                    ans[n - k] = 1;
            }
        }
        ans[n - 1] = 1;
        ref(i, 0, n)
                cout
            << ans[i];
        cout << '\n';
    }
    return 0;
}