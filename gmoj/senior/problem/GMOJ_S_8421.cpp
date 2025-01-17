#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 100;
const int M = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int ny[M + 5], jc[M + 5];
void init()
{
    jc[1] = 1;
    rep(i, 2, M) jc[i] = jc[i - 1] * i % MOD;
    ny[M] = fast_pow(jc[M], MOD - 2);
    reb(i, M, 1) ny[i - 1] = ny[i] * i % MOD;
}

int C(int n, int m)
{
    return jc[n] * ny[m] % MOD * ny[n - m] % MOD;
}

void _change(int &x, int &y)
{
    int nx = x + y, ny = x - y;
    x = nx, y = ny;
}

int n, m;
int x[N], y[N];

int work(int a[])
{
    int res = 0;
    rep(i, a[1] - m, a[1] + m)
    {
        int ans = 1;
        rep(j, 1, n)
        {
            int dis = abs(a[j] - i);
            if (dis <= m && (dis & 1) == (m & 1))
                ans *= C(m, (m - dis) / 2), ans %= MOD;
            else
                ans = 0;
        }
        res = (res + ans) % MOD;
    }
    return res;
}

signed main()
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
        _change(x[i], y[i]);
    }
    cout << work(x) * work(y) % MOD << '\n';
    return 0;
}