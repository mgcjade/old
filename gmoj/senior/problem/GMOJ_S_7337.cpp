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
int a[N];
string str;
int len;

int ch[130];
int st[N], hd; // -1:与,-2:或,-3:异或,-4:左括号,-5:右括号
int ans;

signed main()
{
    ch['x'] = 1, ch['W'] = -1, ch['F'] = -2, ch['Y'] = -3, ch['('] = -4, ch[')'] = -5;
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    cin >> str;
    len = str.length();
    int k = 0;
    ref(i, 0, len)
    {
        hd = 0;
        int tmp = k, flag = 1;
        ref(j, i, len)
        {
            if (flag == 0)
                break;
            if (ch[str[j]] == 1)
                hd++, tmp++, st[hd] = a[tmp];
            else
                ++hd, st[hd] = ch[str[j]];
            while (hd > 1)
            {
                if (st[hd] < 0 && st[hd] > -5)
                    break;
                if (st[hd] == -5)
                {
                    if (hd < 3 || st[hd - 2] != -4)
                    {
                        flag = 0;
                        break;
                    }
                    st[hd - 2] = st[hd - 1], hd -= 2;
                }
                else if (st[hd - 1] >= -3 && st[hd - 1] <= -1)
                {
                    if (st[hd - 1] == -1)
                        st[hd - 2] &= st[hd];
                    else if (st[hd - 1] == -2)
                        st[hd - 2] |= st[hd];
                    else if (st[hd - 1] == -3)
                        st[hd - 2] ^= st[hd];
                    hd -= 2;
                }
                else
                    break;
                ans = max(ans, st[1]);
            }
            // ans = max(ans, st[hd]);
        }
        if (ch[str[i]] == 1)
            k++;
    }
    cout << ans << '\n';
    return 0;
}