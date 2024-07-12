#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int T;
int k;
bool flag;
int n, m;
int a, b;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> k;
        flag = 0;
        while (k--)
        {
            cin >> n >> m;
            cin >> a;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    if (i != 1 || j != 1)
                        cin >> b;
            if (a == 1)
                flag = !flag;
        }
        if (flag)
            cout << "lyp win\n";
        else
            cout << "ld win\n";
    }
    return 0;
}