#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    string str;
    cin >> str;
    int len = str.size();
    while (str[len - 1] == '0')
        len--;
    if (str[len - 1] == '.')
        len--;
    for (int i = 0; i < len; i++)
        cout << str[i];
    return 0;
}