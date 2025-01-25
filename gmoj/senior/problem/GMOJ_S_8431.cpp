#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
pair<int, int> pt[N]; // first 表示该点的次数，second 表示代价
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n) pt[i] = {a[i], 0};
    rep(i, 1, n) q.push({pt[i].first, pt[i].second});
    ref(i, 1, n)
    {
        auto a = q.top();
        q.pop();
        auto b = q.top();
        q.pop();
        q.push({a.first + b.first, a.second + b.second + a.first * 2 + b.first});
        // cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << '\n';
        // cout << q.top().first << " " << q.top().second << '\n';
    }
    cout << q.top().second << '\n';
    return 0;
}