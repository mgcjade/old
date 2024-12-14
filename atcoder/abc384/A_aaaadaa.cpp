#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    char a, b;
    string str;
    cin >> n >> a >> b;
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        if (str[i] != a)
            cout << b;
        else
            cout << a;
    }
    return 0;
}