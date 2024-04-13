#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

string a, b;
int len;
char l, r;
int h, t;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> a >> b;
    len = a.size();
    b[0] += 32, b[1] += 32, b[2] += 32;
    for (int i = 0; i < len; i++)
        if (a[i] == b[0])
            for (int j = i + 1; j < len; j++)
                if (a[j] == b[1])
                {
                    if (b[2] == 'x')
                    {
                        cout << "Yes\n";
                        return 0;
                    }
                    for (int k = j + 1; k < len; k++)
                        if (a[k] == b[2])
                        {
                            cout << "Yes\n";
                            return 0;
                        }
                }
    cout << "No\n";
    return 0;
}