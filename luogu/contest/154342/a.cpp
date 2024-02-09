#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string s;
int len;
map<string, int> mp;
string ans[3];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    mp["acoipp"] = 1, mp["svpoll"] = 2;
    ans[0] = "Boring", ans[1] = "Luogu", ans[2] = "Genshin";
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
        if (s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
    cout << ans[mp[s]];
    return 0;
}