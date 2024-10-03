#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, k;
int x, y;
vector<int> a[N];
int pre[N];
int fnd(int t) { return pre[t] = (pre[t] == t ? t : fnd(pre[t])); }

bool used[N];
int ans;
int flag;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n + m; i++)
        pre[i] = i;
    int u, v;
    while (k--)
    {
        cin >> x >> y;
        if (!used[y + n])
            ans++;
        if (!used[x])
            ans++;
        u = fnd(x);
        v = fnd(y + n);
        if (u != v)
            pre[v] = u, ans--;
        flag = y;
        used[x] = 1, used[y + n] = 1;
    }
    if (flag != 0)
        ans--;
    for (int i = 1; i <= n; i++)
        if (!used[i])
            ans++;
    cout << ans;
    return 0;
}