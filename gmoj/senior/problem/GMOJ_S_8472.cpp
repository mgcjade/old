#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 45;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int l[N], w[N][N], c[N][N];
vector<pair<int, int>> f[N];
int nw[N];
void gt(pair<int, int> &x, pair<int, int> y)
{
    if (x.first > y.first)
        x = y;
    else if (x.first == y.first)
        x.second += y.second;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n)
    {
        cin >> a[i];
    }
    rep(i, 0, n)
    {
        rep(j, i + 1, n)
        {
            c[i][++l[i]] = a[j];
        }
        c[i][++l[i]] = n + 1;
        sort(c[i] + 1, c[i] + l[i] + 1);
        int t = 1;
        rep(j, 1, l[i])
        {
            w[i][j] = t;
            t *= c[i][j] - c[i][j - 1];
        }
        f[i] = vector<pair<int, int>>(t, {INF, 0});
    }
    f[0][0] = {0, 1};
    ref(i, 0, n)
    {
        int _t = 0;
        rep(j, 1, l[i])
        {
            if (c[i][j] == a[i + 1])
                _t = j;
        }
        ref(j, 0, f[i].size())
        {
            int t = j;
            reb(k, l[i], 1)
            {
                nw[k] = t / w[i][k];
                t %= w[i][k];
            }
            int cnt = 0;
            rep(k, _t + 1, l[i])
            {
                cnt += nw[k];
            }
            int t1 = 0, t2 = 0;
            ref(k, 1, _t)
            {
                t1 += nw[k] * w[i + 1][k];
            }
            rep(k, _t + 2, l[i])
            {
                t1 += nw[k] * w[i + 1][k - 1];
            }
            t2 = t1;
            t1 += (nw[_t] + nw[_t + 1]) * w[i + 1][_t];
            t2 += (nw[_t] + nw[_t + 1] + 1) * w[i + 1][_t];
            gt(f[i + 1][t1], f[i][j]);
            gt(f[i + 1][t2], {f[i][j].first + cnt, f[i][j].second});
        }
    }
    rep(i, 1, n)
    {
        cout << f[n][i].first << ' ' << f[n][i].second << '\n';
    }
    return 0;
}