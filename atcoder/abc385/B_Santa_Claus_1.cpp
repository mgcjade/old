#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, m;
int mp[105][105];
string str;
int x, y;
int ans;
bool bz[105][105];

signed main()
{
    memset(bz, 1, sizeof(bz));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    cin >> x >> y;
    rep(i, 1, n)
    {
        cin >> str;
        rep(j, 1, m)
        {
            if (str[j - 1] == '#')
                mp[i][j] = -1;
            else if (str[j - 1] == '.')
                mp[i][j] = 0;
            else
                mp[i][j] = 1;
        }
    }
    cin >> str;
    int len = str.size();
    rep(i, 0, len - 1)
    {
        if (str[i] == 'U')
        {
            if (x > 1 && mp[x - 1][y] != -1)
                x--;
        }
        else if (str[i] == 'D')
        {
            if (x < n && mp[x + 1][y] != -1)
                x++;
        }
        else if (str[i] == 'L')
        {
            if (y > 1 && mp[x][y - 1] != -1)
                y--;
        }
        else if (str[i] == 'R')
        {
            if (y < m && mp[x][y + 1] != -1)
                y++;
        }
        if (bz[x][y] == 1)
        {
            if (mp[x][y] == 1)
                ans++;
            bz[x][y] = 0;
        }
    }
    cout << x << ' ' << y << ' ' << ans;
    return 0;
}