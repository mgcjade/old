#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
ll a[N], b[N];
int nxt[N];
int ans;

int main()
{
    // fre(sequence);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    // for (int i = n; i; i--)
    //     a[i] = a[i] - a[i - 1];
    // for (int j = m; j; j--)
    //     b[j] = b[j] - b[j - 1];
    for (int j = 2; j <= m; j++)
    {
        int k = nxt[j - 1];
        while (b[k + 1] != b[j] && k > 0)
            k = nxt[k];
        if (b[k + 1] == b[j])
            k++;
        nxt[j] = k;
    }
    int j = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] != b[j + 1] && j > 0)
            j = nxt[j];
        if (a[i] == b[j + 1])
            j++;
        if (j == m)
            ans++, j = nxt[j];
    }
    cout << ans << '\n';
    return 0;
}