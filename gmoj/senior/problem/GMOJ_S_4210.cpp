#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
#define int long long

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n;
int a[N];
int tot;
int sum, ans;
int t;

void up(int val)
{
    int k = ++tot;
    a[k] = val;
    while (k > 1 && a[k] < a[k >> 1])
    {
        swap(a[k], a[k >> 1]);
        k >>= 1;
    }
}
int down()
{
    int res = a[1];
    swap(a[1], a[tot]);
    tot--;
    int k = 1;
    while ((a[k * 2] < a[k] && k * 2 <= tot) || (a[k * 2 + 1] < a[k] && k * 2 + 1 <= tot))
    {
        if (a[k * 2 + 1] < a[k * 2] && k * 2 + 1 <= tot)
        {
            swap(a[k], a[k * 2 + 1]);
            k = k * 2 + 1;
        }
        else
        {
            swap(a[k], a[k * 2]);
            k = k * 2;
        }
    }
    ans += res;
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        sum = 0, tot = 0;
        for (int i = 1; i <= n; i++)
            a[i] = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> t;
            up(t);
        }
        ans = 0;
        for (int i = 1; i < n; ++i)
        {
            up(down() + down());
        }
        cout << ans << '\n';
    }
    return 0;
}