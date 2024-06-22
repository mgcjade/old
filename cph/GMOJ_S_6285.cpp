#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, q;
int fa[N];
int x, y;
int ans;

struct node
{
    int to;
    int nxt;
} e[N << 1];
int hd[N], cnt;
void add(int x, int y)
{
    cnt++;
    e[cnt].to = y;
    e[cnt].nxt = hd[x];
    hd[x] = cnt;
}

void dfs(int k)
{
    for (int i = hd[k]; i; i = e[i].nxt)
    {
        int to = e[i].to;
        if (fa[k] != to)
        {
            fa[to] = k;
            dfs(to);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    dfs(1);
    while (q--)
    {
        cin >> x >> y;
        // if (x > y)
        //     swap(x, y);
        ans = y - x + 1;
        for (int i = x; i <= y; i++)
            if (fa[i] >= x && fa[i] <= y)
                ans--;
        cout << ans << '\n';
    }
    return 0;
}