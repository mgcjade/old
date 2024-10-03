#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, T;
string str;
int x;
char y[2];
int ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> T;
    cin >> str;
    for (int i = 0; i < n - 2; i++)
        if (str[i] == 'A' && str[i + 1] == 'B' && str[i + 2] == 'C')
            ans++;
    while (T--)
    {
        cin >> x >> y;
        if (x > 2 && str[x - 3] == 'A' && str[x - 2] == 'B' && str[x - 1] == 'C')
            ans--;
        else if (x > 1 && x + 1 <= n && str[x - 2] == 'A' && str[x - 1] == 'B' && str[x] == 'C')
            ans--;
        else if (x + 2 <= n && str[x - 1] == 'A' && str[x] == 'B' && str[x + 1] == 'C')
            ans--;
        str[x - 1] = y[0];
        // cout << str << ' ';
        if (x > 2 && str[x - 3] == 'A' && str[x - 2] == 'B' && str[x - 1] == 'C')
            ans++;
        else if (x > 1 && x + 1 <= n && str[x - 2] == 'A' && str[x - 1] == 'B' && str[x] == 'C')
            ans++;
        else if (x + 2 <= n && str[x - 1] == 'A' && str[x] == 'B' && str[x + 1] == 'C')
            ans++;
        cout << ans << '\n';
    }
    return 0;
}