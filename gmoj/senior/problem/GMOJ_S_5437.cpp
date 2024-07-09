#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int a[N], b[N];
int nxt[N];
int ans;

int main()
{
    // fre(sequence);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    for (int i = 1; i < n; i++)
        a[i] = a[i + 1] - a[i];
    for (int j = 1; j <= m; j++)
        b[j] = b[j + 1] - b[j];
    n--, m--;
    for (int i = 2; i <= m; i++)
    {
        int j = nxt[i - 1] + 1;
        while (j > 1 && b[j] != b[i])
            j = nxt[j - 1] + 1;
        if (b[j] == b[i])
            nxt[i] = j;
    }
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j > 1 && a[i] != b[j])
            j = nxt[j - 1] + 1;
        if (a[i] == b[j])
            j++;
        if (j == m + 1)
        {
            ans++;
            j = nxt[j - 1] + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}