#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

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
bool check(int a, int b)
{
    int t = a % 10;
    while (a)
    {
        if (a % 10 != t)
            return 0;
        a /= 10;
    }
    while (b)
    {
        if (b % 10 != t)
            return 0;
        b /= 10;
    }
    return 1;
}

int n;
int in;
int ans;

int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(in);
        for (int j = 1; j <= in; j++)
            ans += check(i, j);
    }
    printf("%d", ans);
    return 0;
}