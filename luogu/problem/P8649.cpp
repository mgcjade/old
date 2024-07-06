#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const int N = 1e5;

int n;
int a[N + 5];
int MOD;
int sum[N + 5];
ll ans;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> MOD;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] = (a[i - 1] + a[i]) % MOD;
    }
    for (int i = n; i; i--)
    {
        ans += sum[a[i]] + (a[i] == 0);
        sum[a[i]]++;
    }
    cout << ans;
    return 0;
}