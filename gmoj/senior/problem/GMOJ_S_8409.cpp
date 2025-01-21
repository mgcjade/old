#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

const int pri[] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97}, tot = 25;

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

int n, m;
int to[N];
int ans;
int vis[N];

int tag[N];
int mx[N];
void normal(int x)
{
    int cnt, tmp;
    rep(i, 1, tot)
    {
        tmp = x, cnt = 0;
        while (tmp % pri[i] == 0)
            tmp /= pri[i], cnt++;
        mx[i] = max(mx[i], cnt);
    }
}

int l[N], cnt[N], hd;
int f[N], c[N], p[N];

int dfs(int x, int step)
{
    if (vis[x])
        return vis[x];
    vis[x] = step;
    if (vis[to[x]])
        return step;
    return vis[x] = dfs(to[x], step + 1);
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) cin >> to[i];
    rep(i, 1, m) tag[dfs(i, 1)]++;
    rep(i, 1, m)
    {
        if (!tag[i])
            continue;
        ++hd, l[hd] = i, cnt[hd] = tag[i];
    }
    int s = (1 << hd) - 1;
    rep(i, 1, s)
    {
        int tmp = 0;
        f[i] = 1;
        memset(mx, 0, sizeof(mx));
        for (int j = 1; j <= hd; j++)
        {
            if ((i & (1 << j - 1)) == 0)
                continue;
            c[i]++, tmp = tmp + cnt[j];
            normal(l[j]);
        }
        rep(j, 1, tot) f[i] = f[i] * fast_pow(pri[j], mx[j]) % MOD;
        p[i] = tmp * fast_pow(m, MOD - 2) % MOD;
        p[i] = fast_pow(p[i], n);
    }
    int sum;
    rep(i, 1, s)
    {
        sum = 0;
        rep(j, 1, i)
        {
            if (i - j != (i ^ j))
                continue;
            if ((c[i] - c[j]) & 1)
                sum = (sum - p[j] + MOD) % MOD;
            else
                sum = (sum + p[j]) % MOD;
        }
        ans = (ans + sum * f[i] % MOD) % MOD;
    }
    cout << ans << '\n';
    // rep(i, 1, m) cout << tag[i] << ' ';
    // fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}