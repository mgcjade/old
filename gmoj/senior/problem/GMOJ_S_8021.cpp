#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 21;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n;
int f[1 << N];
int a[N];
char ch[5];

int main()
{
    // fre(landlords);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> ch;
        if (ch[0] >= '3' && ch[0] <= '9')
            a[i] = ch[0] - '0';
        else if (ch[0] == '2')
            a[i] = 1;
        else if (ch[0] == '1')
            a[i] = 10;
        else if (ch[0] == 'A')
            a[i] = 14;
        else if (ch[0] == 'J')
            a[i] = 11;
        else if (ch[0] == 'Q')
            a[i] = 12;
        else if (ch[0] == 'K')
            a[i] = 13;
    }
    sort(a + 1, a + n + 1);
    memset(f, -1, sizeof(f));
    f[(1 << n) - 1] = 0;
    for (int s = (1 << n) - 1; s >= 0; s--)
    {
        if (f[s] == -1)
            continue;
        int lst = 1, sum = 0, lstt = -11, y;
        for (int i = 1, j; i <= n; i++)
        {
            j = n - i + 1;
            // sizhang
            if (a[i] == a[i + 1] && a[i] == a[i + 2] && a[i] == a[i + 3] && s & (1 << j - 1) && s & (1 << j - 2) && s & (1 << j - 3) && s & (1 << j - 4))
                f[s - (1 << j - 1) - (1 << j - 2) - (1 << j - 3) - (1 << j - 4)] = max(f[s - (1 << j - 1) - (1 << j - 2) - (1 << j - 3) - (1 << j - 4)], f[s] + 2);
            // sanzhang
            if (a[i] == a[i + 1] && a[i] == a[i + 2] && s & (1 << j - 1) && s & (1 << j - 2) && s & (1 << j - 3))
                f[s - (1 << j - 1) - (1 << j - 2) - (1 << j - 3)] = max(f[s - (1 << j - 1) - (1 << j - 2) - (1 << j - 3)], f[s] + 1);
            // liangzhang
            if (a[i] == a[i + 1] && s & (1 << j - 1) && s & (1 << j - 2))
                f[s - (1 << j - 1) - (1 << j - 2)] = max(f[s - (1 << j - 1) - (1 << j - 2)], f[s]);
            // shunzi
            if (s & (1 << j - 1))
            {
                if (a[i] == lstt + 1)
                {
                    lst++;
                    sum += (1 << j - 1);
                    lstt++;
                    if (lst >= 5)
                        f[s - sum] = max(f[s], f[s - sum]);
                }
                else if (a[i] == lstt)
                    continue;
                else
                {
                    lst = 1;
                    lstt = a[i];
                    sum = (1 << j - 1);
                }
            }
        }
        sum = 0, y = s;
        while (y)
            y -= (y & -y), sum++;
        if (sum <= f[s] + 1)
        {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
    return 0;
}