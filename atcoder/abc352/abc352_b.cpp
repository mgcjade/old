#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct str
{
    int len;
    string s;
} a, b;

int main()
{
    cin >> a.s;
    cin >> b.s;
    a.len = a.s.length();
    b.len = b.s.length();
    int i = 0, j = 0;
    while (i < a.len && j < b.len)
    {
        while (a.s[i] != b.s[j])
            j++;
        i++, j++;
        cout << j << " ";
    }
    return 0;
}