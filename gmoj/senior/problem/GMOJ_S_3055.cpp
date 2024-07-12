#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;

int n;
double a[N], b[N];
long double ans;
double sum, psum;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b + 1, b + n + 1);
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && b[j] < a[i])
        {
            sum += b[j];
            psum += b[j] * b[j];
            j++;
        }
        ans += ((j - 1) * a[i] * a[i] - 2 * a[i] * sum + psum) / n;
        // cout << fixed << setprecision(1) << ans << '\n';
    }
    j = 1;
    sum = 0, psum = 0;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && a[j] < b[i])
        {
            sum += a[j];
            psum += a[j] * a[j];
            j++;
        }
        ans -= ((j - 1) * b[i] * b[i] - 2 * b[i] * sum + psum) / n;
        // cout << fixed << setprecision(1) << ans << '\n';
    }
    cout << fixed << setprecision(1) << ans << '\n';
    return 0;
}