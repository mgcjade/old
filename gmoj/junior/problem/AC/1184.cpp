#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;

string str[50005];
string in;
char ltr[128];
int n, k;
bool tree[26][26];
int rin[26];
bool vis[26];

string chg(string s)
{
    string ret = "";
    int len = s.size();
    for (int i = 0; i < len; i++)
        ret += ltr[s[i] - 'a'];
    return ret;
}

int main()
{
    fre(ans);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> str[i];
        int len = str[i].size();
        for (int j = 0; j < len; j++)
            vis[str[i][j] - 'a'] = 1;
    }
    cin >> in;

    for (int i = 1; i < k; i++)
    {
        int len = min(str[i].size(), str[i - 1].size());
        int j = 0;
        while (j < len && str[i - 1][j] == str[i][j])
            j++;
        if (j < len && !tree[str[i - 1][j] - 'a'][str[i][j] - 'a'])
            tree[str[i - 1][j] - 'a'][str[i][j] - 'a'] = 1, rin[str[i][j] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            if (tree[i][j] && tree[j][i])
            {
                printf("0");
                return 0;
            }

    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 5; j++)
    //         cout << tree[i][j] << ' ';
    //     cout << endl;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << rin[i] << ' ';
    // }
    // cout << endl;
    int cnt = n;
    int q[30], h = 0, r = 0;
    for (int i = 0; i < 26; i++)
        if (rin[i] == 0 && vis[i])
            q[r++] = i, vis[i] = 0;
    while (h + 1 == r)
    {
        for (int i = 0; i < 26; i++)
            if (tree[q[h]][i])
                rin[i]--;
        ltr[q[h]] = h + 'a';
        // cout << q[h] << ' ' << h << endl;
        h++, cnt--;
        for (int i = 0; i < 26; i++)
            if (rin[i] == 0 && vis[i])
                q[r++] = i, vis[i] = 0;
    }
    if (cnt)
        cout << 0;
    else
        cout << chg(in);

    return 0;
}