#include <bits/stdc++.h>
#define fre(x) freopen(#x ".in", "r", stdin), freopen(#x ".out", "w", stdout)
using namespace std;

const int N = 3e5 + 5;
const int INF = 0x3f3f3f3f;

int n;
char ch[N];
int cnt, cw[N >> 1];
int h, r, cth, ctr;
int ans = INF;

bool _check(int x)
{
    for (int i = 0; i <= cnt; i++)
        if (((cw[i] - 1) >> 1) < x)
            return 0;
    if ((cth > 0 && cth <= x) || (ctr > 0 && ctr <= x))
        return 0;
    return 1;
}
int _cnt(int x)
{
    int ret = 0;
    for (int i = 0; i <= cnt; i++)
        ret += cw[i] - 2 * x;
    ret += max(1, (cth - 1) >> 1) * (cth > 0) + max(1, (ctr - 1) >> 1) * (ctr > 0);
    return ret;
}

int main()
{
    // fre(ans);
    scanf("%d", &n);
    scanf("%s", ch);
    for (h = 0; ch[h] == '1'; h++)
        cth++;
    if (h == n)
    {
        printf("1");
        return 0;
    }
    for (r = n - 1; ch[r] == '1'; r--)
        ctr++;
    h--, r++;
    for (int i = h + 1; i < r; i++)
    {
        if (ch[i] == '1')
            cw[cnt]++;
        else if (cw[cnt] > 0)
            ans = min(ans, cw[cnt]), cnt++;
    }
    while (!_check(ans) && ans > 0)
        ans--;
    printf("%d", _cnt(ans));
    return 0;
}