#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int ch[800][800];
int n;
int s;

void dfs(int pls, int k)
{
    if (k > s)
        return;
    for (int i = 1; i <= s; i += k)
        for (int j = 1; j <= s; j += k)
            for (int x = i + pls; x < i + k - pls; x++)
                for (int y = j + pls; y < j + k - pls; y++)
                    ch[x][y] = 1;
    dfs(pls * 3, k * 3);
}

int main()
{
    cin >> n;
    s = pow(3, n);
    dfs(1, 3);
    for (int i = 1; i <= s; i++)
    {
        for (int j = 1; j <= s; j++)
            if (ch[i][j] == 1)
                cout << '.';
            else
                cout << '#';
        cout << '\n';
    }
    return 0;
}