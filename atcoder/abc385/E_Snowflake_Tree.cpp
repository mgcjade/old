#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int du[N];

vector<int> edge[N];
void add_edge(int u, int v)
{
    edge[u].push_back(v);
    du[u]++;
}

int ans;
int sum[N];
int cnt;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    ref(i, 1, n)
    {
        int x, y;
        cin >> x >> y;
        add_edge(x, y), add_edge(y, x);
    }
    rep(i, 1, n)
    {
        int tp = 0;
        for (auto j : edge[i])
        {
            tp++;
            sum[tp] = du[j];
        }
        sort(sum + 1, sum + tp + 1);
        rep(j, 1, tp)
        {
            ans = max(ans, sum[j] * (tp - j + 1));
        }
    }
    ans = n - ans - 1;
    cout << ans << '\n';
    return 0;
}