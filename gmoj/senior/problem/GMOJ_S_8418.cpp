#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

ll n, ans;
int cnt, tmp;
int ql, qr;
int a[20], b[20], c[20];
int q[205];

bool build(int x, int y)
{
    memset(b, -1, sizeof(b)), memset(c, -1, sizeof(c));
    ql = 1, qr = 0;
    ref(i, x, y)
    {
        if (a[i] > 9)
            return 0;
        else
        {
            c[i] = a[i];
            q[++qr] = 20 + i;
        }
    }
    while (ql <= qr)
    {
        tmp = q[ql];
        if (tmp < 20)
        {
            if ((c[tmp] != -1 && c[tmp] != a[tmp] - b[tmp]) || a[tmp] - b[tmp] < 0 || a[tmp] - b[tmp] >= 10)
                return 0;
            if (c[tmp] == -1)
                q[++qr] = 20 + tmp;
            c[tmp] = a[tmp] - b[tmp];
            if (b[x - tmp] != -1 && b[x - tmp] != b[tmp])
                return 0;
            if (b[x - tmp] == -1)
                q[++qr] = x - tmp;
            b[x - tmp] = b[tmp];
        }
        else
        {
            tmp -= 20;
            if (tmp < x)
            {
                if ((b[tmp] != -1 && b[tmp] != a[tmp] - c[tmp]) || a[tmp] - c[tmp] < 0 || a[tmp] - c[tmp] >= 10)
                    return 0;
                if (b[tmp] == -1)
                    q[++qr] = tmp;
                b[tmp] = a[tmp] - c[tmp];
            }
            if (c[y - tmp] != -1 && c[y - tmp] != c[tmp])
                return 0;
            if (c[y - tmp] == -1)
                q[++qr] = 20 + y - tmp;
            c[y - tmp] = c[tmp];
        }
        ql++;
    }
    if (b[x - 1] == 0 || c[y - 1] == 0)
        return 0;
    return 1;
}
void dfs(int x, ll m)
{
    if (m == 0)
    {
        ll tmp = min(a[1] - 1, 9) - max(a[1] - 9, 1) + 1;
        tmp *= (a[1] == a[x - 1]);
        rep(i, 2, x / 2)
        {
            if (tmp == 0ll)
                break;
            tmp *= min(a[i], 9) - max(a[i] - 9, 0) + 1;
            tmp *= (a[i] == a[x - i]);
        }
        ans += tmp;
        ref(i, 2, x) ans += build(i, x) * 2;
        return;
    }
    if (m > 9)
    {
        a[x] = m % 10 + 10;
        dfs(x + 1, m / 10 - 1);
    }
    a[x] = m % 10;
    dfs(x + 1, m / 10);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dfs(1, n);
    cout << ans << '\n';
    return 0;
}
