#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int lght[N]; // 0:white,1:black
struct edge
{
    int to, nxt;
} a[N];
int hd[N];
bool b[N];

void dfs(int k, bool flag)
{
    if (lght[k] ^ flag)
        flag = !flag, b[k] = 1;
    for (int i = hd[k]; i; i = a[i].nxt)
        dfs(a[i].to, flag);
}

int main()
{
    // fre(tree);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> lght[i];
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].to = y;
        a[i].nxt = hd[x];
        hd[x] = i;
    }
    // if (lght[1] == 0)
    dfs(1, 0);
    // else
    // {
    //     b[1] = 1;
    //     dfs(1, 1);
    // }
    for (int i = 1; i <= n; i++)
        if (b[i])
            cout << i << " ";
    return 0;
}