#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int len, n, l;
string str, t;
int pi[N];
int cnt;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> str;
    len = str.size();
    pi[0] = -1;
    for (int i = 1; i < len; i++)
    {
        int j = pi[i - 1] + 1;
        while (j > 0 && str[j] != str[i])
            j = pi[j - 1] + 1;
        pi[i] = -1;
        if (str[j] == str[i])
            pi[i] = j;
    }
    cin >> t;
    string T = t;
    for (int i = 1; i < n; i++)
        t += T;
    l = t.size();
    int j = -1;
    for (int i = 0; i < l; i++)
    {
        j++;
        while (j > 0 && t[i] != str[j])
            j = pi[j - 1] + 1;
        if (t[i] != str[j])
            j = -1;
        if (j == len - 1)
            cnt++, j = pi[j];
    }
    cout << cnt;
    return 0;
}