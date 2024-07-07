#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n1, m1;
int n2, m2;
int k;
int t;
int sum1, sum2;
int flag, x;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n1 >> m1;
    cin >> n2 >> m2;
    cin >> k;
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= m1; j++)
        {
            cin >> t;
            if (t == 99999)
                flag = (i & 1) ^ (j & 1);
            else if ((i & 1) ^ (j & 1))
                sum1 += (t - k);
            else
                sum2 += (t - k);
        }
    }
    return 0;
}