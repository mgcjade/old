#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 2e5 + 5;

inline void read(int &s)
{
    s = 0;
    char ch = getchar(), last = ' ';
    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();
    while (ch >= '0' && ch <= '9')
        s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
    s = last == '-' ? -s : s;
}

int n, k;
int a[N];
int cnt;
int ans;
int t;

int main()
{
    read(n), read(k);
    for (int i = 1; i <= k; i++)
    {
        read(t);
        a[t] ^= 1;
    }
    t = 0;
    // if (k & 1)
    // {
    int i = 1, j = n;
    while (i < j)
    {
        while (!a[i])
            i++;
        while (!a[j])
            j--;
        if (i < j)
        {
            int x = i + 1, y = j - 1;
            while (!a[x])
                x++;
            while (!a[y])
                y--;
            if (x - i >= j - y)
                ans += j - y, j = y - 1;
            else
                ans += x - i, i = x + 1;
        }
    }
    // }
    // else
    // {
    //     for (int i = 1; i <= n; i++)
    //     {
    //         if (a[i])
    //         {
    //             if (t)
    //                 ans += i - t, t = 0;
    //             else
    //                 t = i;
    //         }
    //     }
    // }
    cout << ans;
    return 0;
}