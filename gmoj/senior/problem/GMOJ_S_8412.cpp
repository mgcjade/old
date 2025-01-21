#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define reb(i, a, b) for (int i = a; i >= b; i--)
#define ref(i, a, b) for (int i = a; i < b; i++)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

template <class _Tp>
void toint(_Tp &s, string &str)
{
    s = 0;
    int i = 0, len = str.length();
    char ch = str[i];
    while (i < len)
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = str[++i];
}

string str;
int len;
int x;

int mx;
string ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> str;
    len = str.length(), ans = str;
    cin >> x;
    int cnt = 0;
    int tmp;
    rep(i, 1, len)
    {
        reb(j, len - 2, 0)
        {
            if (str[j] < str[j + 1])
            {
                ++cnt;
                swap(str[j], str[j + 1]);
                toint(tmp, str);
                tmp -= x * cnt;
                if (tmp > mx)
                {
                    mx = tmp;
                    ans = str;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}