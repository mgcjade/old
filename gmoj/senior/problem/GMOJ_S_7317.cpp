#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
#define md(i) (((i) % MOD + MOD) % MOD)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[30][N], b[30][N];

int L[N], R[N], v[N];
void made(int l, int r)
{
    int x = l, y = r, mai = R[(l + r) / 2];
    while (x < y)
    {
        while (R[x] < mai)
            ++x;
        while (R[y] > mai)
            --y;
        if (x <= y)
        {
            swap(L[x], L[y]), swap(R[x], R[y]), swap(v[x], v[y]);
            ++x, --y;
        }
    }
    if (x < r)
        made(x, r);
    if (l < y)
        made(l, y);
}
void pushdown(int t, int l, int r)
{
    int u = (l + r) / 2 + 1;
    a[t + 1][l] = a[t + 1][l] * b[t][l] % MOD, a[t + 1][u] = a[t + 1][u] * b[t][l] % MOD;
    if (!b[t + 1][l])
        b[t + 1][l] = b[t][l] % MOD;
    else
        b[t + 1][l] = b[t + 1][l] * b[t][l] % MOD;
    if (!b[t + 1][u])
        b[t + 1][u] = b[t][l] % MOD;
    else
        b[t + 1][u] = b[t + 1][u] * b[t][l] % MOD;
    b[t][l] = 0;
}
void add(int t, int l, int r, int x, int y)
{
    if (l > x || r < x)
        return;
    a[t][l] = (a[t][l] + y) % MOD;
    if (l < r)
    {
        if (b[t][l])
            pushdown(t, l, r);
        add(t + 1, l, (l + r) / 2, x, y), add(t + 1, (l + r) / 2 + 1, r, x, y);
        a[t][l] = (a[t + 1][l] + a[t + 1][(l + r) / 2 + 1]) % MOD;
    }
}
void change(int t, int l, int r, int x, int y, int z)
{
    if (r < x || l > y)
        return;
    if (x <= l && r <= y)
    {
        a[t][l] = a[t][l] * z % MOD;
        if (!b[t][l])
            b[t][l] = z;
        else
            b[t][l] = b[t][l] * z % MOD;
        return;
    }
    if (b[t][l])
        pushdown(t, l, r);
    change(t + 1, l, (l + r) / 2, x, y, z), change(t + 1, (l + r) / 2 + 1, r, x, y, z);
    a[t][l] = (a[t + 1][l] + a[t + 1][(l + r) / 2 + 1]) % MOD;
}
int sum(int t, int l, int r, int x, int y)
{
    if (r < x || l > y)
        return 0;
    if (x <= l && r <= y)
        return a[t][l];
    if (b[t][l])
        pushdown(t, l, r);
    return (sum(t + 1, l, (l + r) / 2, x, y) + sum(t + 1, (l + r) / 2 + 1, r, x, y)) % MOD;
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    rep(i, 1, m) cin >> L[i] >> R[i] >> v[i], v[i] %= MOD;
    made(1, m);
    add(0, 0, n, 0, 1);
    rep(i, 1, m)
    {
        int u = sum(0, 0, n, L[i] - 1, R[i]) * v[i] % MOD;
        change(0, 0, n, 0, L[i] - 2, v[i] + 1), add(0, 0, n, R[i], u);
    }
    cout << sum(0, 0, n, n, n) << '\n';
    return 0;
}