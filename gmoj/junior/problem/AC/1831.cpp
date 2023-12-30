#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

int p1, p2, p3;
string s;
string ans;
int len;

void pls(int k)
{
    if (k == 0 || k == len - 1)
    {
        ans += s[k];
        return;
    }
    if (s[k - 1] >= '0' && s[k - 1] <= '9' && s[k + 1] >= 'a' && s[k + 1] <= 'z')
    {
        ans += s[k];
        return;
    }
    if (s[k + 1] >= '0' && s[k + 1] <= '9' && s[k - 1] >= 'a' && s[k - 1] <= 'z')
    {
        ans += s[k];
        return;
    }
    if (s[k - 1] >= s[k + 1])
    {
        ans += s[k];
        return;
    }
    if ((s[k - 1] < '0' || s[k - 1] > 'z' || (s[k - 1] > '9' && s[k - 1] < 'a')) ||
        (s[k + 1] < '0' || s[k + 1] > 'z' || (s[k + 1] > '9' && s[k + 1] < 'a')))
    {
        ans += s[k];
        return;
    }
    if (p3 == 1)
        for (int i = s[k - 1] + 1; i < s[k + 1]; i++)
            for (int j = 1; j <= p2; j++)
                if (p1 == 3)
                    ans += '*';
                else if (p1 == 1)
                    ans += i;
                else if (p1 == 2 && i <= '9' && i >= '0')
                    ans += i;
                else
                    ans += i - 'a' + 'A';
    else
        for (int i = s[k + 1] - 1; i > s[k - 1]; i--)
            for (int j = 1; j <= p2; j++)
                if (p1 == 3)
                    ans += '*';
                else if (p1 == 1)
                    ans += i;
                else if (p1 == 2 && i <= '9' && i >= '0')
                    ans += i;
                else
                    ans += i - 'a' + 'A';
}

int main()
{
    fre(ans);
    cin >> p1 >> p2 >> p3;
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '-')
            pls(i);
        else
            ans += s[i];
    }
    cout << ans;
    return 0;
}