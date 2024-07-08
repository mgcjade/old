#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e2 + 10;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int T;
int a[N][N];
int id[N][N], cnt;
int pre[N * N];

int fnd(int t) { return pre[t] = (pre[t] == t ? t : fnd(pre[t])); }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        cnt = 0;
        for (int i = 0; i <= n + 1; i++)
            for (int j = 0; j <= n + 1; j++)
                cnt++, id[i][j] = cnt, pre[cnt] = cnt;
        int l = ++cnt, r = ++cnt, u = ++cnt, d = ++cnt;
        pre[l] = l, pre[r] = r, pre[u] = u, pre[d] = d;
        for (int i = 1; i <= n; i++)
        {
            pre[fnd(id[0][i])] = pre[fnd(u)];
            a[0][i] = 1;
            pre[fnd(id[n + 1][i])] = pre[fnd(d)];
            a[n + 1][i] = 1;
            pre[fnd(id[i][0])] = pre[fnd(l)];
            a[i][0] = -1;
            pre[fnd(id[i][n + 1])] = pre[fnd(r)];
            a[i][n + 1] = -1;
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] != 0)
                {
                    if (a[i][j + 1] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i][j + 1])];
                    if (a[i][j - 1] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i][j - 1])];
                    if (a[i + 1][j] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i + 1][j])];
                    if (a[i + 1][j - 1] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i + 1][j - 1])];
                    if (a[i - 1][j] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i - 1][j])];
                    if (a[i - 1][j + 1] == a[i][j])
                        pre[fnd(id[i][j])] = pre[fnd(id[i - 1][j + 1])];
                }
        if (pre[fnd(l)] == pre[fnd(r)])
            cout << "Chen\n";
        else if (pre[fnd(u)] == pre[fnd(d)])
            cout << "Jimmy\n";
        else
            cout << "yet\n";
    }
}