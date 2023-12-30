#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

string f, t, s;
char ch[128], table[128];
int used, len;

int main()
{
    fre(ans);
    cin >> f;
    cin >> t;
    cin >> s;
    len = f.size();
    for (int i = 0; i < len; i++)
    {
        if ((ch[f[i]] != 0 && ch[f[i]] != t[i]) || (table[t[i]] != 0 && table[t[i]] != f[i]))
        {
            cout << "Failed\n";
            return 0;
        }
        used += (ch[f[i]] == 0);
        ch[f[i]] = t[i];
        table[t[i]] = f[i];
    }
    if (used < 26)
    {
        cout << "Failed\n";
        return 0;
    }
    len = s.size();
    for (int i = 0; i < len; i++)
        cout << ch[s[i]];
    return 0;
}