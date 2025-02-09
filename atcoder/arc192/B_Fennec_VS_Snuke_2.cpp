#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 10;
int n, ans, sum, a[MAXN];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], ans += (a[i] % 2 == 0);
    if (n >= 4)
    {
        if (ans % 2 == n % 2)
            cout << "Snuke";
        else
            cout << "Fennec";
    }
    else if (n == 1)
        cout << "Fennec";
    else if (n == 2)
        cout << "Snuke";
    else if (n == 3)
    {
        if (ans == n)
            cout << "Snuke";
        else
            cout << "Fennec";
    }
    return 0;
}