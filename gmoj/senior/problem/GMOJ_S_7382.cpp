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

int n;
string str;

const int zero = 9999, one = 7;

void solve()
{
    cin >> n;
    cin >> str;
    int flag = 0;
    int cnt0 = 0, cnt1 = 0;
    ref(i, 0, n)
    {
        if (str[i] == '0')
            cnt0++;
        else
            cnt1++;
    }
    if (cnt0 == 0)
    {
        if (n & 1)
        {
            cout << "Yes\n";
            rep(i, 1, n) cout << one << ' ';
            cout << '\n';
        }
        else
        {
            cout << "No\n";
        }
        return;
    }
    if (cnt1 == 0)
    {
        cout << "Yes\n";
        if (n & 1)
        {
            cout << 6 << ' ' << 9 << ' ';
            rep(i, 3, n) cout << zero << ' ';
        }
        else
        {
            rep(i, 1, n) cout << zero << ' ';
        }
        cout << '\n';
        return;
    }
    if (cnt0 == 1)
    {
        if (cnt1 <= 2)
        {
            cout << "No\n";
            return;
        }
        cout << "Yes\n";
        if (cnt1 & 1)
        {
            rep(i, 1, n)
            {
                if (str[i - 1] - '0')
                    cout << one << ' ';
                else
                    cout << 2 * one << ' ';
            }
        }
        else
        {
            rep(i, 1, n)
            {
                if (str[i - 1] - '0')
                {
                    if (flag == 0)
                        cout << 2 * n - 5 << ' ';
                    else
                        cout << 1 << ' ';
                    flag++;
                }
                else
                    cout << n - 2 << ' ';
            }
        }
        cout << '\n';
        return;
    }
    if (cnt1 & 1)
    {
        cout << "Yes\n";
        if (cnt0 & 1)
        {
            rep(i, 1, n)
            {
                if (str[i - 1] - '0')
                    cout << zero << ' ';
                else
                {
                    if (flag == 0)
                        cout << 6 << ' ';
                    else if (flag == 1)
                        cout << 8 << ' ';
                    else
                        cout << 2 * one << ' ';
                    flag++;
                }
            }
        }
        else
        {
            rep(i, 1, n)
            {
                if (str[i - 1] - '0')
                    cout << one << ' ';
                else
                    cout << zero << ' ';
            }
        }
        cout << '\n';
        return;
    }
    cout << "Yes\n";
    if (cnt0 & 1)
    {
        rep(i, 1, n)
        {
            if (str[i - 1] - '0')
                cout << one << ' ';
            else
            {
                if (flag == 0)
                    cout << 1 << ' ';
                else if (flag == 1)
                    cout << one - 1 << ' ';
                else
                    cout << 2 * one << ' ';
                flag++;
            }
        }
        cout << '\n';
        return;
    }
    rep(i, 1, n)
    {
        if (str[i - 1] - '0')
            cout << zero << ' ';
        else
        {
            if (flag == 0)
                cout << 1 << ' ';
            else if (flag == 1)
                cout << zero - 1 << ' ';
            else
                cout << one << ' ';
            flag++;
        }
    }
    cout << '\n';
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