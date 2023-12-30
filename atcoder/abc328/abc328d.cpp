#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

string str;
int len;

char ch[200005];
int h;

int main()
{
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++)
    {
        ch[h] = str[i];
        h++;
        if (h > 2 && ch[h - 1] == 'C' && ch[h - 2] == 'B' && ch[h - 3] == 'A')
            h -= 3;
    }
    for (int i = 0; i < h; i++)
        cout << ch[i];
    return 0;
}