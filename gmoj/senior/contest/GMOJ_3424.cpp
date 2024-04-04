#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 15;
const int INF = 0x3f3f3f3f;
const ll MOD = 1e9 + 7;

int T;
int n;
int ans;
int c[N];
int sum;

void dfs(int k, int lst)
{
    if (k > sum)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == lst || c[i] == 0)
            continue;
        c[i]--;
        dfs(k + 1, i);
        c[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        sum = 0, ans = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
            sum += c[i];
        }
        dfs(1, 0);
        cout << ans << '\n';
    }
    return 0;
}