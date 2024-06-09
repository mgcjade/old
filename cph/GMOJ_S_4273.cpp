#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1.5e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string str;
int len;
int m;
string s;
int x, y;
int h, a;

int main()
{
    //  fre(elf);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> len >> m;
    cin >> str;
    while (m--)
    {
        cin >> s;
        if (s[0] == 'Q')
        {
            cin >> x >> y;
            h = 0, a = 0;
            for (int i = x - 1; i < y; i++)
            {
                if (str[i] == '(')
                    h++;
                else
                    h--;
                if (h < 0)
                    a++, h = 0;
            }
            cout << a << ' ' << h << '\n';
        }
        else
        {
            cin >> x;
            if (str[x - 1] == '(')
                str[x - 1] = ')';
            else
                str[x - 1] = '(';
        }
    }
    return 0;
}