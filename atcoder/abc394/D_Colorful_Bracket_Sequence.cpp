#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
string str;
char st[N];
int hd;
int check[200][200];

signed main()
{
    check['('][')'] = 1, check['['][']'] = 1, check['<']['>'] = 1;
    cin >> str;
    n = str.length();
    rep(i, 0, n - 1)
    {
        if (hd > 0 && check[st[hd]][str[i]])
            hd--;
        else
            st[++hd] = str[i];
    }
    if (hd)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}