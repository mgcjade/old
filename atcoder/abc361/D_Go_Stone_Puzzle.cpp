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
    char a[17];
};
node a, b;
queue<node> q;
map<node, int> mp;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    char ch[20];
    cin >> ch;
    for (int i = 1; i <= n; i++)
    {
        if (ch[i - 1] == 'B')
            a.a[i] = 1;
    }
    cin >> ch;
    for (int i = 1; i <= n; i++)
    {
        if (ch[i - 1] == 'B')
            b.a[i] = 1;
    }
    a.a[n + 1] = 2, a.a[n + 2] = 2;
    b.a[n + 1] = 2, b.a[n + 2] = 2;
    mp[a] = 0;
    q.push(a);
    while (!q.empty())
    {
        node u = q.front();
        q.pop();
        for (int i = 1; i < 14; i++)
            for (int j = 1; j < 14; j++)
            {
                if (i + 1 < j || j + 1 < i)
                {
                    node v = u;
                    swap(v.a[i], v.a[j]);
                    swap(v.a[i + 1], v.a[j + 1]);
                    if (!mp.count(v))
                    {
                        mp[v] = mp[u] + 1;
                        q.push(v);
                    }
                }
            }
    }
    if (!mp.count(b))
        cout << -1;
    else
        cout << mp[b];
    return 0;
}