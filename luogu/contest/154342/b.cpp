#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout);
using namespace std;
typedef long long ll;

const double INF = 2 * 1e9;
const double MIN = 1e-6;
int n;
double lstl, lstr, t;
double l, r;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    l = -INF, r = INF;
    cin >> n;
    cin >> t;
    lstl = t, lstr = t;
    for (int i = 2; i <= n; i++)
    {
        cin >> t;
        if (lstl - lstr > MIN || l - r > MIN)
            continue;
        if (t > lstr)
            r = min(r, (t + lstr) / 2 - 0.01);
        else if (t < lstl)
            l = max(l, (t + lstl) / 2 + 0.01);
        lstr = max(lstr, t), lstl = min(lstl, t);
    }
    if (fabs(l - r) < MIN || fabs(lstl - lstr) < MIN || l > r || lstl > lstr)
        printf("pigean");
    else
    {
        double ans = (l + r) / 2;
        printf("lovely\n%lf", ans);
    }
    return 0;
}