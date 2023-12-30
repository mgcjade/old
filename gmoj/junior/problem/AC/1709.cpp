#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

int use[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int _check(int n)
{
    int ret = 0;
    do
    {
        ret += use[n % 10];
        n /= 10;
    } while (n);
    return ret;
}

int ans;
int n;
int _ck[2005];

int main()
{
    fre(ans);
    scanf("%d", &n);
    n -= 4;
    for (int i = 0; i <= 2000; i++)
        _ck[i] = _check(i);
    for (int i = 0; i <= 1000; i++)
        if (_ck[i] <= n)
            for (int j = 0; j <= 1000; j++)
                if (_ck[i] + _ck[j] + _ck[i + j] == n)
                    ans++;
    // printf("%d %d %d %d %d %d\n", i, j, i + j, _ck[i], _ck[j], _ck[i + j]);
    printf("%d", ans);
    return 0;
}