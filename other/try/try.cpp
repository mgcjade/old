#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;
typedef long long ll;

const int N = 1e6;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

template <class _Tp>
void read(_Tp &s)
{
    s = 0;
    char ch = getchar(), last = ' ';

    while (ch < '0' || ch > '9')
        last = ch, ch = getchar();

    while (ch >= '0' && ch <= '9')
        s = (s << 3) + (s << 1) + (ch ^ 48), ch = getchar();

    if (last == '-')
        s = -s;
}

int ysf(int n, int m)
{
    if (n == 1)
        return 0;
    if (m == 1)
        return n - 1;
    if (m > n)
        return (ysf(n - 1, m) + m) % n;
    int ret = ysf(n - n / m, m);
    ret -= n % m;
    if (ret < 0)
        ret += n;
    else
        ret += ret / (m - 1);
    return ret;
}

int n, m;

int main()
{
    fre(ysf14);
    read(n), read(m);
    printf("%d\n", ysf(n, m) + 1);
    return 0;
}