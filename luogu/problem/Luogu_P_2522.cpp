#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 5e4 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int sum[N], mu[N];
bool vis[N];
int pri[N], cnt;
void init(int n)
{
    mu[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            mu[i] = -1;
            pri[++cnt] = i;
        }
        for (int j = 1; j <= cnt && i * pri[j] <= n; j++)
        {
            vis[i * pri[j]] = 1;
            if (i % pri[j] == 0)
                break;
            mu[i * pri[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + mu[i];
}

int solve(int n, int m, int k)
{
    if (n == 0 || m == 0)
        return 0;
    int res = 0;
    n /= k, m /= k;
    if (n > m)
        swap(n, m);
    for (int l = 1, r; l <= n; l = r + 1)
    {
        r = min(n / (n / l), m / (m / l));
        res += (n / l) * (m / l) * (sum[r] - sum[l - 1]);
    }
    return res;
}

int n;
int a, b, c, d, k;
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    init(5e4);
    while (n--)
    {
        cin >> a >> b >> c >> d >> k;
        ans = solve(b, d, k) + solve(a - 1, c - 1, k) - solve(b, c - 1, k) - solve(a - 1, d, k);
        cout << ans << '\n';
    }
    return 0;
}