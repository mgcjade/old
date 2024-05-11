#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct Tp
{
    double a;
    int p, w;
    int num;
};
bool operator<(Tp x, Tp y) { return x.a > y.a; }
priority_queue<Tp> t;
Tp ans[N];
bool cmp(Tp x, Tp y) { return x.num < y.num; }

int n, m;
int sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    Tp tp;
    for (int i = 1; i <= n; i++)
    {
        tp.num = i;
        cin >> tp.p >> tp.w;
        tp.a = tp.w / 1.0 / tp.p;
        t.push(tp);
        sum += tp.w;
    }
    if (sum > m)
    {
        cout << "Zip file size too big after extraction.Poor M!";
        return 0;
    }
    int cnt = 0;
    while (sum < m && !t.empty())
    {
        tp = t.top();
        t.pop();
        if (tp.w >= tp.p)
        {
            ans[++cnt] = tp;
            if (ans[0] < tp)
                ans[0] = tp;
            continue;
        }
        tp.w++;
        tp.a = tp.w / 1.0 / tp.p;
        t.push(tp);
        sum++;
    }
    if (!t.empty())
        ans[0] = t.top();
    if (ans[0].w == 0)
        cout << "0/1\n";
    else
        cout << ans[0].w / __gcd(ans[0].w, ans[0].p) << '/' << ans[0].p / __gcd(ans[0].w, ans[0].p) << '\n';
    while (!t.empty())
    {
        ans[++cnt] = t.top();
        t.pop();
    }
    sort(ans + 1, ans + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        cout << ans[i].w << ' ';
    return 0;
}