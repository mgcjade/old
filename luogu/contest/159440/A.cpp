#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e7 + 5;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string str;
int T;
int len;
int sum[N];
int v[128];
int q;
int x, y;

int main()
{
    v['P'] = 3, v['p'] = 2, v['G'] = 1;
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> T;
    while (T--)
    {
        cin >> str;
        len = str.size();
        for (int i = 1; i <= len; i++)
            sum[i] = sum[i - 1] + v[str[i - 1]];
        cin >> q;
        while (q--)
        {
            cin >> x >> y;
            cout << sum[y] - sum[x - 1] << '\n';
        }
    }
    return 0;
}