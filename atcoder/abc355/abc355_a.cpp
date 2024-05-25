#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
        cout << -1;
    else
    {
        int vis[3];
        vis[a - 1] = 1, vis[b - 1] = 1;
        for (int i = 0; i < 3; i++)
        if (!vis[i])
            cout << i + 1;
    }
    return 0;
}