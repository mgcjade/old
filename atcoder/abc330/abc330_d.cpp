#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
char ch[2005][2005];
ll ans;
ll l[2005], h[2005];

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%s", ch[i] + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            h[i] += (ch[i][j] == 'o'), l[j] += (ch[i][j] == 'o');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (ch[i][j] == 'o')
                ans += (h[i] - 1) * (l[j] - 1);
    printf("%lld", ans);
    return 0;
}