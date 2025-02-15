#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "cnt", stdout)
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int long long

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
string str;
int sum, cnt;
int ans;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    ref(i, 0, n) if (str[i] == '1') sum++;
    if (sum == 1)
    {
        cout << "0";
        return 0;
    }
    sum = (sum + 1) / 2;
    ref(i, 0, n)
    {
        if (str[i] == '1')
            cnt++;
        if (cnt == sum)
        {
            cnt = i;
            break;
        }
    }
    int l = cnt - 1, r = cnt + 1, x = 0, y = 0;
    while (l >= 0)
    {
        if (str[l] == '1')
            ans += cnt - l - x - 1, x++;
        l--;
    }
    while (r < n)
    {
        if (str[r] == '1')
            ans += r - cnt - y - 1, y++;
        r++;
    }
    cout << ans << '\n';
    return 0;
}