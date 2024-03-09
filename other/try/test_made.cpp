#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int nxt[N];
int ans[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
        nxt[i] = i % n + 1;
    int j = n;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 1; k < i; k++)
            j = nxt[j];
        ans[nxt[j]] = i;
        nxt[j] = nxt[nxt[j]];
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
    return 0;
}