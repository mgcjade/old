#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const double MIN = 1e-10;
const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int xa, ya;
int xb, yb;
int xc, yc;
double a, b, c;

int main()
{
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;
    a = sqrt((xb - xa) * (xb - xa) + (yb - ya) * (yb - ya));
    b = sqrt((xc - xa) * (xc - xa) + (yc - ya) * (yc - ya));
    c = sqrt((xc - xb) * (xc - xb) + (yc - yb) * (yc - yb));
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
    if (fabs(a * a + b * b - c * c) <= MIN)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}