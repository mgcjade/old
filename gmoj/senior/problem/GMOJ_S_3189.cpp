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

void read();
void init();

int n, m;
map<string, int> mp;
// int a[N + 5], b[N + 5];
int lsta[N + 5], lstb[N + 5];

int pi[N + 5];

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    read();
    init();
    // kmp
    int j = 0;
    rep(i, 1, n)
    {
        while (j != 0 && !((lstb[j + 1] < 0 && lsta[i] < i - j) || (j + 1 - lstb[j + 1] == i - lsta[i])))
            j = pi[j];
        if ((lstb[j + 1] < 0 && lsta[i] < i - j) || (j + 1 - lstb[j + 1] == i - lsta[i]))
            j++;
        if (j >= m)
            return cout << i - j + 1 << '\n', 0;
    }
    cout << -1;
    fprintf(stderr, "#%.3lf", 1.0 * clock() / CLOCKS_PER_SEC);
    return 0;
}
// 判断法则：((lstb[j + 1] < 0 && lstb[i] < i - j) || (j + 1 - lstb[j + 1] == i - lstb[i]))

void init()
{
    // cerr << n << ' ' << m << '\n';
    // rep(i, 1, n) cerr << a[i] << " \n"[i == n];
    // rep(i, 1, m) cerr << b[i] << " \n"[i == m];
    // kmp
    pi[1] = 0;
    rep(i, 2, m)
    {
        int j = pi[i - 1];
        while (j != 0 && !((lstb[j + 1] < 0 && lstb[i] < i - j) || (j + 1 - lstb[j + 1] == i - lstb[i])))
            j = pi[j];
        if ((lstb[j + 1] < 0 && lstb[i] < i - j) || (j + 1 - lstb[j + 1] == i - lstb[i]))
            pi[i] = j + 1;
    }
    // rep(i, 1, m) cerr << pi[i] << " \n"[i == m];
}

void read()
{
    string s;
    int cnt = 0, num = 0;
    cin >> s;
    while (s != "$")
    {
        ++cnt;
        if (mp.find(s) == mp.end())
        {
            ++num;
            mp[s] = cnt;
            // a[cnt] = num;
            lsta[cnt] = -1;
        }
        else
        {
            lsta[cnt] = mp[s];
            mp[s] = cnt;
            // a[cnt] = a[lsta[cnt]];
        }
        cin >> s;
    }
    n = cnt;

    cnt = 0, num = 0;
    mp.clear();
    cin >> s;
    while (s != "$")
    {
        ++cnt;
        if (mp.find(s) == mp.end())
        {
            ++num;
            mp[s] = cnt;
            // b[cnt] = num;
            lstb[cnt] = -1;
        }
        else
        {
            lstb[cnt] = mp[s];
            mp[s] = cnt;
            // b[cnt] = b[lstb[cnt]];
        }
        cin >> s;
    }
    m = cnt;
}