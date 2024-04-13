#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int len;
int vis[27];
string str;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++)
        vis[str[i] - 'a']++;
    sort(vis, vis + 26);
    for (int i = 25; i > 0; i -= 2)
    {
        if ((vis[i] != vis[i - 1] || vis[i] == vis[i + 1]) && vis[i] != 0)
        {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    return 0;
}