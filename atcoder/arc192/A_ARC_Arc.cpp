#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 6e5 + 10;
const int mod = 998244353;
int n, m, a[N], ans;
string s, t;
signed main()
{
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i], sum += (a[i] == 0);
    if (sum == n)
    {
        if (n & 1 || (n / 2) & 1)
            cout << "No";
        else
            cout << "Yes";
        return 0;
    }
    if (sum == 0)
    {
        cout << "Yes";
        return 0;
    }
    int pos = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == 1)
        {
            pos = i;
            break;
        }
    for (int i = pos; i <= pos + n - 1; i++)
    {
        if (a[i] == 1)
            continue;
        int j = i;
        while (j <= pos + n - 1)
        {
            while (j <= pos + n - 1 && a[j] == 0)
                j++;
            j--;
            if ((j - i + 1) % 2 == 0)
                break;
            if (j == pos + n - 2)
            {
                cout << "Yes";
                return 0;
            }
            if (j == pos + n - 1)
            {
                if (a[pos + 1])
                    cout << "Yes";
                else
                {
                    if (i == pos + 1)
                    {
                        if (((j - i + 1) / 2) & 1)
                            cout << "Yes";
                        else
                            cout << "No";
                    }
                    else
                    {
                        cout << "Yes";
                    }
                }
                return 0;
            }
            if (a[j + 1] && a[j + 2])
                break;
            j += 2;
        }
        i = j;
    }
    cout << "Yes";
    return 0;
}
