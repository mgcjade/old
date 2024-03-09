#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string str;
int len;
bool flag;

int main()
{
    cin >> str;
    len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '|')
            flag = !flag;
        else if (!flag)
            cout << str[i];
    }
    return 0;
}