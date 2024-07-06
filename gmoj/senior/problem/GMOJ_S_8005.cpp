#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int a[N];
int ans;
bool check(int x, int y)
{
    double b = (a[y] - a[x]) / 1.0 / (y - x);
    for (int i = x + 1; i < y; i++)
        if (a[i] >= a[x] + b * (i - x))
            return false;
    // cout << x << " " << y << endl;
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += check(i, j);
    cout << ans << endl;
    return 0;
}