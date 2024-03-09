#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
struct node
{
    int v;
    int pre, nxt;
};
node a[N];
int hd, en;
int q;
int op, x, y;
map<int, int> mp;
int t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].v;
        mp[a[i].v] = i;
    }
    for (int i = 2; i <= n; i++)
        a[i].pre = i - 1, a[i - 1].nxt = i;
    hd = 1, en = n;
    cin >> q;
    while (q--)
    {
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y;
            t = mp[x];
            en++;
            a[en].v = y;
            a[a[t].nxt].pre = en;
            a[en].nxt = a[t].nxt;
            a[en].pre = t;
            a[t].nxt = en;
            mp[y] = en;
        }
        else
        {
            cin >> x;
            t = mp[x];
            a[a[t].pre].nxt = a[t].nxt;
            a[a[t].nxt].pre = a[t].pre;
            a[t].nxt = a[t].pre = a[t].v = 0;
        }
    }
    for (int i = en; i; i--)
        if (a[i].pre == 0 && a[i].v != 0)
        {
            t = i;
            break;
        }
    for (; a[t].nxt; t = a[t].nxt)
        cout << a[t].v << ' ';
    cout << a[t].v;
    return 0;
}