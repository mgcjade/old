#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a, b;
int v[15];
vector<vector<int>> c[15];
int ans;

int t[N], cnt;
void dg(int k)
{
    t[++cnt] = k;
    if (k <= 0)
    {
        vector<int> ad;
        reb(i, cnt, 1) ad.push_back(t[i]);
        c[cnt].push_back(ad);
        cnt--;
        return;
    }
    dg(k - a), dg(k - b);
    cnt--;
}
void check(vector<int> x, vector<int> y)
{
    for (auto i : y)
        x.push_back(i);
    sort(x.begin(), x.end());
    for (auto i : x)
        cerr << i << ' ';
    cerr << '\n';
    int len = x.size(), res = 0;
    ref(i, 2, len - 1)
        res += (x[i + 1] - x[i]) * (v[x[i + 1]] ^ v[x[i]]),
        cerr << (x[i + 1] - x[i]) << ' ' << (v[x[i + 1]] ^ v[x[i]]) << ' ' << res << ' ';
    ans = max(ans, res);
    cerr << res << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b;
    rep(i, 1, n) cin >> v[i];
    dg(n);
    rep(i, 1, n + 1) sort(c[i].begin(), c[i].end());
    rep(i, 1, n + 1) for (auto j : c[i])
    {
        for (auto kk : j)
            cerr << kk << " ";
        cerr << "\n";
    }
    int k = (n - 1) / a + 2;
    rep(i, (n - 1) / b + 2, k)
    {
        for (auto tp : c[i])
        {
            for (auto j : c[i])
            {
                if (tp[0] != j[0])
                    continue;
                check(tp, j);
            }
        }
        // while (!c[i].empty())
        // {
        //     vector<int> tp = c[i].front();
        //     for (auto j : c[i])
        //     {
        //         if (tp[0] != j[0])
        //             continue;
        //         check(tp, j);
        //     }
        //     c[i].erase(c[i].begin());
        // }
    }
    cout << ans << '\n';
    return 0;
}