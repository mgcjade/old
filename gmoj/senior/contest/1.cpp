#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
double v[N + 5];
int a[N + 5];
double ans;

void dg(int k, double s)
{
    if (int(ceil(s)) == 0)
        return;
    if (k > n)
    {
        int t = 0, flag = 0;
        for (int i = 1; i <= n; i++)
            if (a[i])
                flag++;
            else
                t += flag * flag * flag, flag = 0;
        t += flag * flag * flag, flag = 0;
        ans += s * t;
        return;
    }
    a[k] = 0;
    dg(k + 1, s * (1 - v[k]));
    a[k] = 1;
    dg(k + 1, s * v[k]);
}

int main()
{
    fre(ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    dg(1, 1);
    cout << fixed << setprecision(1) << ans;
    return 0;
}