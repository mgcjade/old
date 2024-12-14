#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, t, x, y, z, fx, fy, fz, ans;
int flagx[2050][2050], flagy[2050][2050], flagz[2050][2050];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> t;
    int tar = n * (n + 1) / 2;
    while (t--)
    {
        cin >> x >> y >> z;
        flagx[y][z] += x + 1;
        flagy[x][z] += y + 1;
        flagz[x][y] += z + 1;
        ans += flagx[y][z] == tar;
        ans += flagy[x][z] == tar;
        ans += flagz[x][y] == tar;
        cout << ans << '\n';
    }
}
