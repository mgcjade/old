#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int a[10];
struct node
{
    string name;
    int marks;
};
node ans[50];
int cnt;

char ch[10] = {' ', 'A', 'B', 'C', 'D', 'E'};
void dfs(int k, string s, int sum)
{
    if (k > 5)
    {
        if (s == "")
            return;
        ++cnt;
        ans[cnt].marks = sum;
        ans[cnt].name = s;
        return;
    }
    dfs(k + 1, s, sum);
    dfs(k + 1, s + ch[k], sum + a[k]);
}
bool cmp(node x, node y)
{
    if (x.marks == y.marks)
        return x.name < y.name;
    return x.marks > y.marks;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
    dfs(1, "", 0);
    sort(ans + 1, ans + cnt + 1, cmp);
    for (int i = 1; i <= cnt; i++)
        cout << ans[i].name << '\n';
    return 0;
}