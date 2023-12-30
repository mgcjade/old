#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int len, q;
string str;
int sum[300005];

int main()
{
    cin >> len >> q;
    cin >> str;
    for (int i = 1; i < len; i++)
        sum[i] = sum[i - 1] + (str[i] == str[i - 1]);
    // for (int i = 1; i < len; i++)
    //     cout << sum[i] << ' ';
    int a, b;
    while (q--)
    {
        cin >> a >> b;
        cout << sum[b - 1] - sum[a - 1] << "\n";
    }
    return 0;
}