#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 5e5 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
string str[N];
int len[N];
int a[N], cnt;
int ans;
void check()
{
    int mn = INF, mx = 0;
    for (int i = 1; i <= cnt; i++)
        mn = min(mn, len[a[i]]), mx = max(mn, len[a[i]]);
    if (mx - mn > 1)
        return;
    bool flag = true;
    for (int i = 0; i < mn && flag; i++)
    {
        for (int j = 1; j < cnt && flag; j++)
            if (str[a[j]][len[a[j]] - i - 1] != str[a[+1]][len[a[j + 1]] - i - 1])
                flag = false;
    }
    if (flag)
        ans = max(ans, cnt);
}
void dfs(int k)
{
    if (k > n)
    {
        check();
        return;
    }
    dfs(k + 1);
    a[++cnt] = k;
    dfs(k + 1);
    cnt--;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // fre(rhyme);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        len[i] = str[i].size();
    }
    dfs(1);
    cout << ans;
    return 0;
}