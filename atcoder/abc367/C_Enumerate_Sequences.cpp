#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k;
int mx[N];
int a[N];

void dfs(int x)
{
    if (x > n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
            sum += a[i];
        if (sum % k == 0)
        {
            for (int i = 1; i <= n; i++)
                cout << a[i] << ' ';
            cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= mx[x]; i++)
    {
        a[x] = i;
        dfs(x + 1);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> mx[i];
    dfs(1);
    return 0;
}