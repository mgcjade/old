#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, k;
int a[N], b[N], w[N];
int cnt;
int ans = INF;
int t, u, v;

int fre[N];
int fnd(int t) { return t == fre[t] ? t : fre[t] = fnd(fre[t]); }
int lowbit(int t) { return t & (-t); }
bool check()
{
    for (int i = 1; i <= k; i++)
        if (fnd(i) != fnd(n - i + 1))
            return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        cin >> a[i] >> b[i] >> w[i];
    int s = pow(2, m);
    for (int i = 0; i < s; i++)
    {
        for (int j = 1; j <= n; j++)
            fre[j] = j;
        cnt = 0;
        for (int j = i; j; j -= lowbit(j))
        {
            t = __lg(lowbit(j)) + 1;
            cnt += w[t];
            u = fnd(a[t]), v = fnd(b[t]);
            if (u != v)
                fre[u] = v;
        }
        if (check())
            ans = min(ans, cnt);
    }
    cout << (ans == INF ? -1 : ans) << '\n';
    return 0;
}