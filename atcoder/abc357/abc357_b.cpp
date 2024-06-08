#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string str;
string ans;
int len;
int cnta, cntb;

int main()
{
    cin >> str;
    len = str.length();
    for (int i = 0; i < len; i++)
        if (str[i] >= 'a')
            cnta++;
        else
            cntb++;
    if (cnta > cntb)
        for (int i = 0; i < len; i++)
            if (str[i] >= 'a')
                ans += str[i];
            else
                ans += char(str[i] - 'A' + 'a');
    else
        for (int i = 0; i < len; i++)
            if (str[i] <= 'Z')
                ans += str[i];
            else
                ans += char(str[i] - 'a' + 'A');
    cout << ans;
    return 0;
}