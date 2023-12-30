#include <bits/stdc++.h>
using namespace std;

int n, l, ans, t;

int main()
{
    scanf("%d%d", &n, &l);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &t);
        ans += (t >= l);
    }
    printf("%d", ans);
    return 0;
}
