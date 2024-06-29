#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int cnt[N];
int t;
int sum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        sum += !cnt[t];
        cnt[t]++;
    }
    if (sum & 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i])
        {
            cout << i << ' ';
            cnt[i]--;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        while (cnt[i])
        {
            cout << i << ' ';
            cnt[i]--;
        }
    }
    cout << '\n';
    return 0;
}