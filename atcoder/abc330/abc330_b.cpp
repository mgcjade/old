#include <bits/stdc++.h>
using namespace std;

int n, l, r;
int a[200005];

int main()
{
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        if (a[i] <= l)
            printf("%d ", l);
        else if (a[i] >= r)
            printf("%d ", r);
        else
            printf("%d ", a[i]);
    }
    return 0;
}