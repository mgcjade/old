#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    if (last == '-')
        s = -s;
}

string s;
int len;
int ans;

int main()
{
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
        if (s[i] == '.')
            ans = i;
    for (int i = ans + 1; i < len; i++)
        cout << s[i];
    return 0;
}