#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;
// #define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int n;
int len;
string stra, strb;
int ans;

char a, b, c;

void solve1()
{
    int sum = 1;
    ref(i, 0, len)
    {
        if (i & 1)
        {
            if ((stra[i] != '?' && stra[i] != b) || (strb[i] != '?' && strb[i] == c))
                return;
            if (strb[i] == '?')
                sum *= 2;
        }
        else
        {
            if ((stra[i] != '?' && stra[i] != a) || (strb[i] != '?' && strb[i] != c))
                return;
        }
    }
    ans += sum;
}
void solve2()
{
    int sum = 1;
    int alb = -1, arc = len, blb = -1, brc = len;
    ref(i, 0, len)
    {
        if (i & 1)
        {
            if ((stra[i] != '?' && stra[i] != a) || (strb[i] != '?' && strb[i] != a))
                return;
        }
        else
        {
            if ((stra[i] != '?' && stra[i] == a) || (strb[i] != '?' && strb[i] == a))
                return;
            if (stra[i] == b)
                alb = i;
            else
                arc = min(arc, i);
            if (strb[i] == c)
                blb = i;
            else
                brc = min(brc, i);
        }
    }
    if (alb > arc || blb > brc || alb > brc || blb > arc || alb < 0 || blb < 0 || arc >= len || brc >= len)
        return;
    sum = pow(2, min(arc, brc) - max(alb, blb));
    ans += sum;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> n;
        cin >> stra >> strb;
        len = 2 * n + 1;
        ans = 0;
        rep(i, 'A', 'C') rep(j, 'A', 'C') rep(k, 'A', 'C') if (i != j && j != k && i != k)
        {
            a = i, b = j, c = k;
            cout << a << " " << b << " " << c << ' ';
            solve1();
            cout << ans << ' ';
            solve2();
            cout << ans << '\n';
        }
        cout << ans << "\n";
    }
    return 0;
}