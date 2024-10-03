#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
string str;
int f[N][2];

char ch[130];

int main()
{
    ch['R'] = 0;
    ch['P'] = 1;
    ch['S'] = 2;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        char lst = str[i - 2], nw = str[i - 1];
        if (lst == nw)
        {
            f[i][0] = f[i - 1][1];
            f[i][1] = f[i - 1][0] + 1;
        }
        else if ((ch[lst] + 1) % 3 == ch[nw])
        {
            f[i][0] = f[i - 1][0];
            f[i][1] = max(f[i - 1][0], f[i - 1][1]) + 1;
        }
        else
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1]);
            f[i][1] = f[i - 1][1] + 1;
        }
    }
    cout << max(f[n][0], f[n][1]) << "\n";
    return 0;
}