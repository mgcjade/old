#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 2e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m, x;
pair<int, int> a[N + 5];
int tlt[N + 5];
pair<int, int> lt[N + 5];
int tot;
bool ans[N + 5];

int main()
{
    // fre(ans);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++)
    {
        if (a[i].first <= lt[tot].second)
            lt[tot].second = max(lt[tot].second, a[i].second);
        else
            lt[++tot].first = a[i].first, lt[tot].second = a[i].second;
        tlt[i] = tot;
    }
    for (int i = 1; i <= m; i++)
    {
        if (lt[tlt[i]].first <= x && lt[tlt[i]].second >= x)
        {
            if (a[i].first < x)
                ans[a[i].first] = 1;
            if (a[i].second > x)
                ans[a[i].second] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        if (ans[i])
            cout << i << ' ';
    return 0;
}