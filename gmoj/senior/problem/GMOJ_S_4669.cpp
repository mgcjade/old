#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string str;
int len;
int pi[N];
int m;
int a, b;

int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    cin >> str;
    len = str.size();
    // cout << "0 ";
    for (int i = 2; i <= len; i++)
    {
        int j = pi[i - 1] + 1;
        while (j > 1 && str[i - 1] != str[j - 1])
            j = pi[j - 1] + 1;
        pi[i] = 0;
        if (str[i - 1] == str[j - 1])
            pi[i] = j;
        // cout << pi[i] << " ";
    }
    // cout << "\n";
    cin >> m;
    while (m--)
    {
        cin >> a >> b;
        if (str[a - 1] != str[b - 1])
        {
            cout << "0 0\n";
            continue;
        }
        while (a != b && a && b)
        {
            if (pi[a] > pi[b])
                a = pi[a];
            else
                b = pi[b];
        }
        if (a != b)
        {
            cout << "0 0\n";
            continue;
        }
        int cnt = 0;
        while (a > 0)
        {
            cnt++;
            a = pi[a];
        }
        // cnt += (str[0] == str[b - 1] && b > 1);
        cout << cnt << ' ' << b << '\n';
    }
    return 0;
}