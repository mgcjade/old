#include <bits/stdc++.h>
#define For(i, a, b) for (int i = a; i <= b; i++)
using namespace std;

int n, f;
string s, t;
map<string, int> mp;
set<string> st;

void mkt(int x, int y, int z) { t = "", t += s[x], t += s[y], t += s[z]; }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> f >> s;
    s = " " + s;
    For(i, 1, n - 2)
    {
        if (s[i] != s[i + 1] && s[i + 1] == s[i + 2])
        {
            mkt(i, i + 1, i + 2), ++mp[t];
            if (mp[t] >= f)
                st.insert(t);
        }
    }
    For(i, 1, n)
    {
        if (i > 2 && s[i - 2] != s[i - 1] && s[i - 1] == s[i])
            mkt(i - 2, i - 1, i), --mp[t];
        if (i > 1 && i < n && s[i - 1] != s[i] && s[i] == s[i + 1])
            mkt(i - 1, i, i + 1), --mp[t];
        if (i < n - 1 && s[i] != s[i + 1] && s[i + 1] == s[i + 2])
            mkt(i, i + 1, i + 2), --mp[t];
        For(j, 0, 25)
        {
            char now = 'a' + j;
            if (i > 2)
            {
                if (s[i - 2] != s[i - 1] && s[i - 1] == now)
                {
                    t = "", t += s[i - 2], t += s[i - 1], t += now;
                    if (mp[t] + 1 >= f)
                        st.insert(t);
                }
            }
            if (i > 1 && i < n)
            {
                if (s[i - 1] != now && now == s[i + 1])
                {
                    t = "", t += s[i - 1], t += now, t += s[i + 1];
                    if (mp[t] + 1 >= f)
                        st.insert(t);
                }
            }
            if (i < n - 1)
            {
                if (now != s[i + 1] && s[i + 1] == s[i + 2])
                {
                    t = "", t += now, t += s[i + 1], t += s[i + 2];
                    if (mp[t] + 1 >= f)
                        st.insert(t);
                }
            }
        }
        if (i > 2 && s[i - 2] != s[i - 1] && s[i - 1] == s[i])
            mkt(i - 2, i - 1, i), ++mp[t];
        if (i > 1 && i < n && s[i - 1] != s[i] && s[i] == s[i + 1])
            mkt(i - 1, i, i + 1), ++mp[t];
        if (i < n - 1 && s[i] != s[i + 1] && s[i + 1] == s[i + 2])
            mkt(i, i + 1, i + 2), ++mp[t];
    }
    cout << st.size() << '\n';
    for (auto tmp : st)
    {
        cout << tmp << '\n';
    }
}
