#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 505;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
struct node
{
    int x, y;
    int u, v;
} t[N];
int a[N];
vector<int> e[N];
int ans;
int mn, w;

bool cmp(node x, node y) { return x.u == y.u ? x.v > y.v : x.u < y.u; }

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + k; j <= n; j++)
            if (a[i] > a[j])
            {
                e[i].push_back(j);
                ans++;
            }
    cout << ans << '\n';
    int cnt;
    while (ans > 0)
    {
        cnt = 0;
        mn = n + 1;
        for (int i = 1; i <= n; i++)
            if (e[i].size() && a[i] < mn)
                mn = a[i], w = i;
        ans -= e[w].size();
        for (int j = e[w].size() - 1; j >= 0; j--)
        {
            int to = e[w][j];
            cnt++;
            t[cnt].x = w, t[cnt].y = to;
            t[cnt].u = a[w], t[cnt].v = a[to];
        }
        sort(t + 1, t + cnt + 1, cmp);
        for (int i = 1; i <= cnt; i++)
        {
            cout << t[i].x << ' ' << t[i].y << '\n';
            swap(a[t[i].x], a[t[i].y]);
        }
        e[w].clear();
    }
    return 0;
}