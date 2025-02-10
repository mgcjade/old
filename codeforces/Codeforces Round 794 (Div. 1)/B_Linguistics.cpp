#include <bits/stdc++.h>
#define fre(tmp) freopen(#tmp ".in", "r", stdin), freopen(#tmp ".out", "w", stdout)
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
int a, b, c, d;
string str;

int check()
{
    int cnta = 0, cntb = 0;
    ref(i, 0, n)
    {
        if (str[i] == 'A')
            ++cnta;
        else
            ++cntb;
    }
    return (cnta == a + c + d) && (cntb == b + c + d);
}
void ok(int &x, int tmp, int &y)
{
    if (x >= tmp)
        x -= tmp;
    else
        tmp -= x + 1, x = 0, y -= min(y, tmp);
}

int solve()
{
    cin >> a >> b >> c >> d;
    cin >> str;
    n = str.size();
    if (check() == 0)
        return cout << "NO\n", 0;
    int cd = 0;
    std::vector<int> C, D;
    for (int i = 0; i < n;)
    {
        int j = i + 1;
        while (j < n && str[j] != str[j - 1])
            ++j;
        int len = j - i;
        if (len == 1)
        {
            i = j;
            continue;
        }
        if (len & 1)
            cd += len / 2;
        else
        {
            len /= 2;
            if (str[i] == 'A')
                C.push_back(len);
            else
                D.push_back(len);
        }
        i = j;
    }
    sort(C.begin(), C.end()), sort(D.begin(), D.end());
    for (int i : C)
        ok(c, i, d);
    for (int i : D)
        ok(d, i, c);
    if (cd >= c + d)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}