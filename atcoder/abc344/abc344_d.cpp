#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
int len;
int n;
int a[105];
string str[105][15];
int lent[105][15];
int f[105][105];

bool check(string ss, int l, int le)
{
    for (int i = le - l, j = 0; i < le; i++, j++)
        if (s[i] != ss[j])
            return 0;
    return 1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> s;
    len = s.size();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        for (int j = 1; j <= a[i]; j++)
        {
            cin >> str[i][j];
            lent[i][j] = str[i][j].size();
        }
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 0; i < n; i++)
        f[i][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= len; j++)
        {
            f[i][j] = f[i - 1][j];
            for (int k = 1; k <= a[i]; k++)
                if (lent[i][k] <= j && check(str[i][k], lent[i][k], j))
                    f[i][j] = min(f[i][j], f[i - 1][j - lent[i][k]] + 1);
        }
    if (f[n][len] == INF)
        cout << "-1";
    else
        cout << f[n][len];
    return 0;
}