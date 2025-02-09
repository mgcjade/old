#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 105;
const int M = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int k[N];
vector<int> a[N];
int flag[M];

int sum[M][2];
double check(int x, int y)
{
    double res = 0;
    for (auto i : a[x])
        sum[i][0]++;
    for (auto i : a[y])
        sum[i][1]++;
    for (auto i : a[y])
        if (!flag[i])
            flag[i] = 1, res += sum[i][1] * 1.0 / k[y] * sum[i][0] / k[x];
    for (auto i : a[x])
        sum[i][0]--;
    for (auto i : a[y])
        flag[i] = 0, sum[i][1]--;
    return res;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int tmp;
    rep(i, 1, n)
    {
        cin >> k[i];
        rep(j, 1, k[i])
        {
            cin >> tmp;
            a[i].push_back(tmp);
        }
    }
    double ans = 0;
    rep(i, 1, n) rep(j, i + 1, n)
        ans = max(ans, check(i, j));
    cout << fixed << setprecision(15) << ans;
    return 0;
}